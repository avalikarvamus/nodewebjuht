const char * htmlMessage = R"=====(
<!DOCTYPE html>
<html><head>
<meta http-equiv="content-type" content="text/html; charset=UTF-8">
<script>
</script>
<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">
<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.3.1/css/all.css" integrity="sha384-mzrmE5qonljUremFsqc01SB46JvROS7bZs3IO2EmfFsd15uHvIt+Y8vEf7N7fWAU" crossorigin="anonymous">
<style>
.nupp   {width: 82px !important;}
.mnp    {width: 42px !important;}
#frame {padding: 12px; }
</style>
</head>
<body>
<div id="frame">
Green Led is now: <div id="led">Off</div>
<button type="button" class="btn btn-success nupp" id="greenled"><i class="fas fa-traffic-light"></i></button>
<br>
Temperature: <div id="celsius"></div>
<br>
<div id="result"></div>
<p>
  <button type="button" class="btn btn-success nupp" id="ledon"><i class="far fa-lightbulb"></i></button>
  <button type="button" class="btn btn-danger nupp" id="ledoff"><i class="fas fa-lightbulb"></i></button>
  <br>
</p>
<p>
  <button type="button" class="btn btn-primary mnp" id="left"><i class="fas fa-angle-left"></i></button>
  <button type="button" class="btn btn-success nupp" id="start"><i class="far fa-arrow-alt-circle-up"></i></button>
  <button type="button" class="btn btn-primary mnp" id="right"><i class="fas fa-angle-right"></i></button>
</p>
<p>
  <button type="button" class="btn btn-primary mnp" id="uleft"><i class="fas fa-angle-double-left"></i></button>
  <button type="button" class="btn btn-danger nupp" id="stop"><i class="far fa-stop-circle"></i></button>
  <button type="button" class="btn btn-primary mnp" id="uright"><i class="fas fa-angle-double-right"></i></button>
</p>
<p>
  <button type="button" class="btn btn-primary mnp" id="bleft"><i class="fas fa-angle-down"></i></button>
  <button type="button" class="btn btn-success nupp" id="back"><i class="far fa-arrow-alt-circle-down"></i></button>
  <button type="button" class="btn btn-primary mnp" id="bright"><i class="fas fa-angle-down"></i></button>
</p>
<br>
<textarea id="rxConsole"></textarea>
<br>
<textarea id="celsiusLog"></textarea>
</div>
<script src="https://code.jquery.com/jquery-3.3.1.min.js" crossorigin="anonymous"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/js/bootstrap.min.js" integrity="sha384-ChfqqxuZUCnJSK3+MXmPNIyE6ZbWh2IMqE241rYiqJxyMiZ6OW/JmZQ5stwEULTy" crossorigin="anonymous"></script>
<script src="microajax.js"></script>
</body>
</html>
)=====";
