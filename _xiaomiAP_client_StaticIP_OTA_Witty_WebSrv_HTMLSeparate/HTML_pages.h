const static char html_main_page[] PROGMEM = R"=====(
 <!DOCTYPE html>
<html>
<head>
	<title></title>
	<meta charset='utf-8'>
	<!--адаптиция под телефон-->
	<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
  <style> 
  button, input[type='button']{ 
    font-size:1em;
    border-radius:30px;
    margin: 5px;
    }
    
    .niceBut1{
      background-color:rgb(86, 173, 210);
      color: rgb(255, 255, 255);
      box-shadow: 0px 2px 5px 0px rgba(0, 0, 0, 0.5);
    }
    .niceBut2{
      background-color:rgb(10, 10, 10);
      color: rgb(255, 255, 255);
      box-shadow: 0px 2px 5px 0px rgba(0, 0, 0, 0.5);
    }
  </style>
</head>
<body>
<center><h1>Комфортный дом </h1></center>
<br>
<br><br><br>

<br><br><br>
<input type='button' value='Красный Вкл' onclick="location.href='leds?red=1';">
<input type='button' value='Зеленый Вкл'onclick="location.href='leds?green=1';">
<input type='button' value='Синий Вкл' onclick= "location.href='leds?blue=1';" >
<br>





<script>
var slider1=document.getElementById('slider1');
var a;
var prev_a;
var o = document.getElementById("out");
a=slider1.value;

function js_slider(){
  console.log("leds?slider1=" + a);
location.href='leds?slider1='+a; 
}
</script>

<input type="range" name="slider1" id="slider1" value="" min="0" max="255" step="1" onimput="js_slider()">
<output id="out" for="slider1"> КРАСНЕНЬКОЙ </output>




<br>
<button onclick="location.href='leds?eff=1';" class="niceBut1" >
Эффект 1 
</button>
<br>
<button onclick="location.href='leds?eff=2';" class="niceBut2" >
Эффект 2 
</button>

<br><br><br>
<input type='button' value='Красный Потушить' style='width:200Px;height:200Px' onclick="location.href='leds?red=0';">
<input type='button' value='Зеленый Потушить' style='width:200Px;height:200Px' onclick="location.href='leds?green=0';">
<input type='button' value='Синий Потушить' style='width:200Px;height:200Px' onclick="location.href='leds?blue=0';">

<br><br><br><br><br><br>
<input type='button' value='ОЙ ВСЕ' style='width:600Px;height:300Px' onclick="location.href='leds?lamp=-1';">


<br><br><br><br><br><br><br><br><br>
</body>
</html>
)=====";



