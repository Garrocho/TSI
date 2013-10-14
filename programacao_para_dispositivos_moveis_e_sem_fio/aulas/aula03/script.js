function suporta_html5_storage() {
    try {
        return 'localStorage' in window && window['localStorage'] != null;
    }catch (e) {
        return false;
    }
}

//alert(suporta_html5_storage());
//localStorage.setItem('versao', '0.1')
//alert(localStorage.getItem('versao'));
//alert(localStorage.length);
//localStorage.removeItem('versao');
//localStorage.clear();

var user = {
    'id': 5,
    'nome': 'João',
    'tels': ['123', '456']
}

localStorage['user'] = JSON.stringify(user);

alert(JSON.parse(localStorage['user'])['id']);
