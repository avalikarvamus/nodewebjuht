const char PAGE_Root[] PROGMEM = R"=====(
<!DOCTYPE html>
<html><head>
<meta http-equiv="content-type" content="text/html; charset=windows-1257">
<script type="text/javascript">// Promises
</script>
<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">
<style>
.nupp   {width: 78px !important;}
</style>
</head>
<body>Led pin is now: Off
<br>
Temperature: <div id="celsius"></div>
<br>
<div id="result"></div>
<p>
  <button type="button" class="btn btn-success nupp" id="ledon">Turn On</button>
  <button type="button" class="btn btn-danger nupp" id="ledoff">Turn Off</button>
  <br>
</p>
<p>
  <button type="button" class="btn btn-primary nupp" id="left">Left</button>
  <button type="button" class="btn btn-primary nupp" id="right">Right</button>
<br>
  <button type="button" class="btn btn-success nupp" id="start">Start</button>
  <button type="button" class="btn btn-danger nupp" id="stop">Stop</button>
</p>

<script src="https://code.jquery.com/jquery-3.3.1.min.js" crossorigin="anonymous"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js" integrity="sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy" crossorigin="anonymous"></script>
<script src="script.js"></script>
</body>
</html>
)=====";

void sendRootPage()
{
    if (server.args() > 0 )  // Are there any POST/GET Fields ?
    {
       for ( uint8_t i = 0; i < server.args(); i++ ) {  // Iterate through the fields

        }
    }
    server.send ( 200, "text/html", PAGE_Root );
}
