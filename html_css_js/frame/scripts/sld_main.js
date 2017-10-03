 // Javascript

// To draw stuff in canvas
var sld = document.getElementById("sld_area");
var sldc = sld.getContext('2d');
document.addEventListener("DOMContentLoaded", init, false);

function init()
{
    var canvas = document.getElementById("sld_area");
    canvas.addEventListener("mousedown", getPosition, false);
}

function getPosition(event)
{
    var x = new Number();
    var y = new Number();
    var canvas = document.getElementById("sld_area");


    if (event.x != undefined && event.y != undefined)
    {
        x = event.x;
        y = event.y;
    }
    else // Firefox method to get the position
    {
        alert('hi');
        x = event.clientX + document.body.scrollLeft +
            document.documentElement.scrollLeft;
        y = event.clientY + document.body.scrollTop +
            document.documentElement.scrollTop;
    }

    x -= canvas.offsetLeft;
    y -= canvas.offsetTop;

    //alert("x: " + x + "  y: " + y);

    sldc.fillStyle = 'red';
    sldc.fillRect(x, y, 5, 10);
}

init();

/*
  var sld = document.getElementById("sld_area");
   var sldc = sld.getContext('2d');

  function getCursorPosition(event) {
  var rect = sld.getBoundingClientRect();
  var x = event.clientX - rect.left;
  var y = event.clientY - rect.top;
  console.log("x: " + x + " y: " + y);
  }

  function drawBus(e) {
  var rect = sld.getBoundingClientRect();
  var x = e.clientX - rect.left;
  var y = e.clientY - rect.top;
  console.log("x: " + x + " y: " + y);
  sldc.fillStyle = 'red';
  sldc.fillRect(x, y, 5, 10);
  console.log(e);
  }

  function onSldClick(e) {
  
  // if (e.ctrlKey) {
  drawBus(e);
  // }    
  }

  sld.addEventListener("mousedown", function(e){ onSldClick(e); });
*/
