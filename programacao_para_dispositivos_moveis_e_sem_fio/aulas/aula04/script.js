function handleFileSelect(evt) {
var files = evt.target.files;
var output = [];
for (var i = 0, f; f = files[i]; i++) {
output.push('<li><strong>', escape(f.name), '</strong> (', f.type || 'n/a', ') - ',
f.size, ' bytes, última modificação: ',
f.lastModifiedDate.toLocaleDateString(), '</li>');
}
document.getElementById('list').innerHTML = '<ul>' + output.join('') + '</ul>';
}
document.getElementById('files').addEventListener('change', handleFileSelect, false);


var canvas = document.getElementById('tela');
var context = canvas.getContext('2d');
var centerX = canvas.width / 2;
var centerY = canvas.height / 2;
var radius = 70;

context.beginPath();
context.arc(centerX, centerY, radius, 0, 2 * Math.PI, false);
context.fillStyle = 'white';
context.fill();
context.lineWidth = 5;
context.strokeStyle = '#003300';
context.stroke();

context.beginPath();
context.arc(centerX, centerY, radius-15, 3.1, 2 * Math.PI, true);
context.fillStyle = '#0099FF';
context.fill();

context.beginPath();
context.arc(centerX-30, centerY-30, radius-55, 0, 2 * Math.PI, true);
context.fillStyle = '#0099FF';
context.fill();

context.beginPath();
context.arc(centerX+30, centerY-30, radius-55, 0, 2 * Math.PI, true);
context.fillStyle = '#0099FF';
context.fill();
