$(document).ready(function(){
    //alert('Quantidade de parágrafos: ' + $('p').size());
    //alert('Segundo parágrafo: ' + $('#p2').text());
    //alert('Terceiro parágrafo: ' + $('.p3').text());
    //alert('Primeiro parágrafo após o título: ' + $('h1 + p').text());
    //alert('HTML do rodapé: ' + $('footer').html());
    $('#p1').text('Novo texto');
    $('#p2').html('Novo texto com <strong>HTML</strong>');
    
    //$('button').click(function(){
    //    alert('Ok!');
    //});
    
    //$('button').mouseover(function(){
    //    alert('Mouse sobre o botão');
    //});
    
    $('botao_paragrafo').click(function(){
        if ($('#paragrafo').is(':visible')) {
            $(this).text('Exibir Paragrafo');
            $('#paragrafo').fadeOut();
            //$(this).css({'width':'300px'});
            $(this).addClass('novo_estilo');
        }
        else {
            $(this).text('Ocultar Paragrafo');
            $('#paragrafo').fadeIn();
        }
    });
    
    $('#botao_area').click(function(){
        if ($('#texto').val().length > 0) {
            alert($('#texto').val());
        }
        else {
            alert('Escreva um Texto!');
        }
    });
    
});
