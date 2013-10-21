$(document).ready(function() {
    var ids = localStorage.getItem('ids');
    if (ids == null) {
        ids = 0;
        localStorage.setItem('ids', ids);
        var comp = {};
        comp[ids] = {
            'titulo': 'Reunião Importante',
            'texto': 'reuniao com os conselheiros...' };
        localStorage['comp'] = JSON.stringify(comp);
        $('#lista').append('<div data-role="collapsible"><h4>' + comps[0]['titulo'] + '</h4> <p>' + comps[0]['texto'] + '</p> </div>');
    }
    else {
        var comps = JSON.parse(localStorage.getItem('comp'));
        var i;
        for (i=0; i <= ids; i++) {
            $('#lista').append('<div data-role="collapsible"><h4>' + comps[i]['titulo'] + '</h4> <p>' + comps[i]['texto'] + '</p> </div>');
        }
    }
});

function cadastrar() {
    var titulo = document.getElementById('titulo_compromisso').value;
    var texto = document.getElementById('texto_compromisso').value;

    if (titulo.length > 0 && texto.length > 0) {
        var ids = parseInt(localStorage.getItem('ids'))+1;
        var comps = JSON.parse(localStorage['comp']);
        comps[ids] = {
            'titulo': titulo,
            'texto': texto };
        localStorage.setItem('ids', ids);
        localStorage['comp'] = JSON.stringify(comps);
        $('#lista').append('<div data-role="collapsible"><h4>' + comps[ids]['titulo'] + '</h4> <p>' + comps[ids]['texto'] + '</p> </div>');
    }
    else {
        alert('Preencha Todos Os Campos do Cadastro de Compromissos!');
    }
}