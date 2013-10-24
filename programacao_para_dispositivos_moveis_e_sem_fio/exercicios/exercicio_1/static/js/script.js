$(document).ready(function() {
    validacao();
    limpar_busca();
});

function limpar_busca() {
    document.getElementById("lista").innerHTML="";
    var ids = localStorage.getItem('ids');
    if (ids != null) {
        var comps = JSON.parse(localStorage.getItem('comp'));
        var i;
        for (i=0; i <= ids; i++) {
            if (typeof comps[i] === 'undefined') {
                
            }
            else {
                $('#lista').append('<div data-role="collapsible"><h4>' + comps[i]['titulo'] + '</h4> <p>ID: ' + i + '</p> <p>Descrição: ' + comps[i]['texto'] + '</p> <p>Data: ' + comps[i]['data'] + '</p> </div>').trigger('create');
            }
        }
    }
}

function validacao() {
    var ids = localStorage.getItem('ids');
    if (ids == null) {
        localStorage.setItem('ids', 0);
        var comps = {};
        localStorage['comp'] = JSON.stringify(comps);
    }
}

function cadastrar() {
    var titulo = document.getElementById('titulo_compromisso').value;
    var texto = document.getElementById('texto_compromisso').value;
    var data = document.getElementById('data_compromisso').value;

    if (titulo.length > 0 && texto.length > 0) {
        var ids = parseInt(localStorage.getItem('ids'))+1;
        var comps = JSON.parse(localStorage['comp']);
        comps[ids] = {
            'titulo': titulo,
            'texto': texto,
            'data': data };
        localStorage.setItem('ids', ids);
        localStorage['comp'] = JSON.stringify(comps);
        alert('Compromisso com ID ' + ids + ' Cadastrado com Sucesso!');   
        window.location.href = 'index.html';
    }
    else {
        alert('Preencha Todos Os Campos do Cadastro de Compromissos!');
    }
}

function data_atual_formatada() {
    var data = new Date();
    var dia = data.getDate();
    var mes = data.getMonth();
    var ano4 = data.getFullYear();
    return ano4 + '-' + (mes+1) + '-' + dia;
}

function listar_por_data() {
    var data_atual = data_atual_formatada();
    document.getElementById('lista').innerHTML="";
    var ids = parseInt(localStorage.getItem('ids'))+1;
    var comps = JSON.parse(localStorage['comp']);
    var i;
    for (i=0; i <= ids; i++) {
        if (typeof comps[i] === 'undefined') {
            
        }
        else {
            if (comps[i]['data'] === data_atual) {
                $('#lista').append('<div data-role="collapsible"><h4>' + comps[i]['titulo'] + '</h4> <p>ID: ' + i + '</p> <p>Descrição: ' + comps[i]['texto'] + '</p> <p>Data: ' + comps[i]['data'] + '</p> </div>').trigger('create');
            }
        }
    }
}

function deletar() {
   var id_comp = document.getElementById('id_compromisso').value;
   if (id_comp.length > 0) {
        var comps = JSON.parse(localStorage['comp']);
        if (typeof comps[id_comp] === 'undefined') {
            alert('ID Inexistente!');
        }
        else {
            delete comps[id_comp];
            localStorage['comp'] = JSON.stringify(comps);
            alert('Compromisso com ID ' + id_comp + ' Deletado com Sucesso!');
            window.location.href = 'index.html';
        }
    }
    else {
        alert('Preencha o Campo com o ID a ser excluído!');
    }
}

function deletar_tudo() {
    localStorage.removeItem('comp');
    localStorage.removeItem('ids');
    alert('Todos os Compromissos Deletados com Sucesso!');   
    window.location.href = 'index.html';
}
