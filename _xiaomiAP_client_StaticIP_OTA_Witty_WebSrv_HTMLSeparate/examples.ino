
          
                /// нагугленное \\\



/*
Возможный вариант, надо проверять ...

  client.print("<form method=get><br><font size='6'>Red:  </font></h1><input type='range' min='1' max='100' name=redVal value=");
  client.print(redTemp);  //set the value of the slider based upon the previous page load value
  client.println(" style='height:30px; width:200px' oninput='showRedValue(this.value)'>");    //was onchange event
  client.print("<span id='redrange'>");
  client.print(redTemp);  //set the javascript initial value
  client.println("</span>");
  client.println("<script type='text/javascript'>\r\nfunction showRedValue(newValue)\r\n{\r\ndocument.getElementById('redrange').innerHTML=newValue;\r\n}\r\n</script>\r\n");

*/

// also from there

/*


  //first slider
    client.print("<form method=get><br>Red:  <input type='range' min='1' max='100' name=redVal value=redTemp oninput='showValue(this.value)'>");
    client.println("<span id='range'>0</span>");
    client.println("<script type='text/javascript'>\r\nfunction showValue(newValue)\r\n{\r\ndocument.getElementById('range').innerHTML=newValue;\r\n}\r\n</script>\r\n");

    //second slider
    client.print("<br><br>Green:  <input type='range' min='1' max='100' name=greVal value=greTemp oninput='showValue1(this.value)'>");
    client.println("<span id='range1'>0</span>");
    client.println("<script type='text/javascript'>\r\nfunction showValue1(newValue)\r\n{\r\ndocument.getElementById('range1').innerHTML=newValue;\r\n}\r\n</script>\r\n");

    //third slider
    client.print("<br><br>Blue:  <input type='range' min='1' max='100' name=bluVal value=bluTemp oninput='showValue2(this.value)'>");
    client.println("<span id='range2'>0</span>");
    client.println("<script type='text/javascript'>\r\nfunction showValue2(newValue)\r\n{\r\ndocument.getElementById('range2').innerHTML=newValue;\r\n}\r\n</script>\r\n");
*/


/*
// https://randomnerdtutorials.com/esp32-servo-motor-web-server-arduino-ide/
// good example
// see more in vkladka scetch

  <input type="range" min="0" max="180" class="slider" id="servoSlider" onchange="servo(this.value)"/>


  var slider = document.getElementById("servoSlider");
  var servoP = document.getElementById("servoPos");
  servoP.innerHTML = slider.value;
  slider.oninput = function() {
   slider.value = this.value;
   servoP.innerHTML = this.value;
  }


  $.ajaxSetup({timeout:1000});
  function servo(pos) {
  $.get("/?value=" + pos + "&");
  }


*/

