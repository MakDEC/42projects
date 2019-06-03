#!/usr/bin/php
<?php
$stock = array("buchenoel" => "10", "buchechocolat" => "10", "buchefraise" => "10");
$stock2 = array("ckchocolat" => "10", "ckcaramel" => "10", "ckfraise" => "10");
$stock3 = array("annivanille" => "10", "anniframboise" => "10", "annichocolat" => "10");
$stock = array_merge($stock, $stock2, $stock3);
file_put_contents("private/stock", serialize($stock));
?>
