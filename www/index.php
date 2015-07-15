<?php
$light = $_GET['light'];
if($light == "on") {
  $file = fopen("light.json", "w") or die("can't open file");
  fwrite($file, '{"light": "on"}');
  fclose($file);
} 
else if ($light == "off") {
  $file = fopen("light.json", "w") or die("can't open file");
  fwrite($file, '{"light": "off"}');
  fclose($file);
}
?>

<html>
  <head>      
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    
    <title>LED for ESP8266</title>
   
    <script src="https://code.jquery.com/jquery-2.1.4.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.4/js/bootstrap.min.js"></script>
    <link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.4/css/bootstrap.min.css" rel="stylesheet">
    <link rel="stylesheet" href="//maxcdn.bootstrapcdn.com/font-awesome/4.3.0/css/font-awesome.min.css">

  </head>
  <body>
    <div class="row" style="margin-top: 20px;">
      <div class="col-md-8 col-md-offset-2">
        <a href="?light=on" class="btn btn-success btn-block btn-lg">Turn On</a>
        <br />
        <a href="?light=off" class="led btn btn-danger btn-block btn-lg">Turn Off</a>
        <br />
        <div class="light-status well" style="margin-top: 5px; text-align:center">
          <?php
            if($light=="on") {
              echo("Turn LED on.");
            }
            else if ($light=="off") {
              echo("Turn LED off.");
            }
            else {
              echo ("Do something.");
            }
          ?>
        </div>
      </div>
    </div>
  </body>
</html>
