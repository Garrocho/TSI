$(document).ready(function() {
    var ids = localStorage['ids'];
    if (ids == null) {
        ids = [1];
        var comp = {};
        for (i in ids) {
            comp[ids[i]] = {
                'titulo': 'Reunião Importante',
                'texto': 'reuniao com os conselheiros...' };
            localStorage['ids'] = JSON.stringify(ids);
            localStorage['comp'] = JSON.stringify(comp);
        }
    }
    else {
        ids = JSON.parse(ids);
        var comps = JSON.parse(localStorage.getItem('comp'));
        for (i in ids) {
            $('#lista').append('<div data-role="collapsible"><h4>' + comps[ids[i]]['titulo'] + '</h4> <p>' + comps[ids[i]]['texto'] + '</p> </div>');
        }
    }
});
