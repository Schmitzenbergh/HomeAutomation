


<form action="" method="post">
  <input type="submit" name="On" value="On" />
  <input type="submit" name="Off" value="Off" />
</form>
<form action="" method="post">
  <input type="submit" name="Up" value="Up" />
  <input type="submit" name="Down" value="Down" />
  <input type="submit" name="Left" value="Left" />
  <input type="submit" name="Right" value="Right" />
</form>
<form action="" method="post">
  <input type="submit" name="Pause" value="Pause" />
  <input type="submit" name="Play" value="Play" />
  <input type="submit" name="Next" value="Next" /> 
  <input type="submit" name="Previous" value="Previous" />    
</form>
<form action="" method="post">
  <input type="submit" name="Forward" value="Forward" />
  <input type="submit" name="Back" value="Back" />  
</form>
<form action="" method="post">
  <input type="submit" name="MuteToggle" value="MuteToggle" />
  <input type="submit" name="VolumeUp" value="VolumeUp" />
  <input type="submit" name="VolumeDown" value="VolumeDown" />
</form>
<form action="" method="post">  


  <input type="submit" name="Info" value="Info" />
  <input type="submit" name="HeartAlive" value="HeartAlive" />
  <input type="submit" name="Reverse" value="Reverse" />
  <input type="submit" name="Sleep" value="Sleep" />

</form>
<form action="" method="post">  
  <input type="submit" name="Home" value="Home" />
  <input type="submit" name="SelectSource" value="SelectSource" />
  <input type="submit" name="Options" value="Options" />  
  <input type="submit" name="Ok" value="Ok" />
  <input type="submit" name="Radio" value="Radio" />
</form>


<?php

	$loader = require __DIR__ . '/vendor/autoload.php';
	$hk = new \HKAPI\API('192.168.0.98', 10025, new \HKAPI\Devices\AVR());		
	
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['Pause'])){ $hk->zone('Main Zone')->Pause(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['Up'])){ $hk->zone('Main Zone')->Up(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['Next'])){ $hk->zone('Main Zone')->Next(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['MuteToggle'])){ $hk->zone('Main Zone')->MuteToggle(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['Options'])){ $hk->zone('Main Zone')->Options(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['Previous'])){ $hk->zone('Main Zone')->Previous(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['SelectSource'])){ $hk->zone('Main Zone')->SelectSource(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['HeartAlive'])){ $hk->zone('Main Zone')->HeartAlive(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['VolumeUp'])){ $hk->zone('Main Zone')->VolumeUp(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['Back'])){ $hk->zone('Main Zone')->Back(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['Reverse'])){ $hk->zone('Main Zone')->Reverse(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['Off'])){ $hk->zone('Main Zone')->Off(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['Left'])){ $hk->zone('Main Zone')->Left(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['Forward'])){ $hk->zone('Main Zone')->Forward(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['Right'])){ $hk->zone('Main Zone')->Right(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['Info'])){ $hk->zone('Main Zone')->Info(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['Sleep'])){ $hk->zone('Main Zone')->Sleep(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['Down'])){ $hk->zone('Main Zone')->Down(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['Play'])){ $hk->zone('Main Zone')->Play(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['Ok'])){ $hk->zone('Main Zone')->Ok(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['On'])){ $hk->zone('Main Zone')->On(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['VolumeDown'])){ $hk->zone('Main Zone')->VolumeDown(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['Home'])){ $hk->zone('Main Zone')->Home(); }
  if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['Radio'])){ $hk->zone('Main Zone')->Radio(); }
    
?>


