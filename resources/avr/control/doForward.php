
<?php

	$loader = require __DIR__ . './../../../src/HKAPI/vendor/autoload.php';
	$hk = new \HKAPI\API('192.168.0.98', 10025, new \HKAPI\Devices\AVR());
	$hk->zone('Main Zone')->Forward();		

?>
