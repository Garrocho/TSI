//alert(document.getElementById('azul').textContent);
document.getElementById('azul').style.color = "#000";
document.getElementById('azul').innerHTML = "TESTANDO";
//document.getElementById('azul').style.display = 'none';
document.getElementById('azul').onclick = function () {
    alert('oi');
    document.getElementById('azul').innerHTML = "MUDOU O TEXTO";
}
var i = 0;
function trocarCor() {
    if (i == 0) {
        document.getElementById('azul').style.color = "#000";
        i = 1;
        }
    else {
        document.getElementById('azul').style.color = "#fff";
        i = 0;
    }
}
