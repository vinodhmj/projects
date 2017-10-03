// javascript file


var canvas = document.getElementById('canvas');
var ctx = canvas.getContext('2d');

function getMousePos(evt) {
    var rect = canvas.getBoundingClientRect();
    var normalX = (rect.right-rect.left) * canvas.width;
    var normalY = (rect.bottom-rect.top) * canvas.height;
    return {
        x: (evt.clientX - rect.left) / normalX,
        y: (evt.clientY - rect.top) / normalY
    };
}

function draw_can(event)
{
    ctx.fillStyle = 'red';
    var pos = getMousePos(event);
    ctx.fillRect(pos.x, pos.y, 5, 10);
    console.log(event);
}
canvas.addEventListener("click", function(e) { draw_can(e); }, false);
