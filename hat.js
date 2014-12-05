var johnny = require("johnny-five")
  , q = require('q')
  , board = new johnny.Board();



function slowFade(minBrightness, maxBrightness, duration, repeat){
  var led = new johnny.Led(11);
  led.fade(maxBrightness, duration/2);

  setTimeout(function(){
    led.fade(minBrightness, duration/2);
  }, duration/2);

  if(repeat === true){
    setTimeout(function(){
      slowFade(minBrightness, maxBrightness, duration, repeat)
    }, duration);
  }
}




board.on('ready', function(){
  slowFade(0, 255, 5000, true);
});




//function Sensor(){
//  this.type = 'sound';
//  this.position = {
//    x: 0
//  , y: 0
//  , z: 0
//  };
//  this.listen = function(){}
//  this.emit = function(){}
//}


