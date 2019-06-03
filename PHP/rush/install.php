#!/usr/bin/php
<?php
if (!file_exists("private"))
			mkdir("private");
$stock = array("buchenoel" => "10", "buchechocolat" => "10", "buchefraise" => "10");
$stock2 = array("ckchocolat" => "10", "ckcaramel" => "10", "ckfraise" => "10");
$stock3 = array("annivanille" => "10", "anniframboise" => "10", "annichocolat" => "10");
$stock = array_merge($stock, $stock2, $stock3);
file_put_contents("private/stock", serialize($stock));
$users[0] = serialize(array("login" => "admin", "passwd" => hash("sha1", "admin"), "admin" => "1"));
$users[1] = serialize(array("login" => "massoud", "passwd" => hash("sha1", "motdepassse"), "admin" => "1"));
$users[2] = serialize(array("login" => "antoine", "passwd" => hash("sha1", "mdp"), "admin" => "1"));
$users[3] = serialize(array("login" => "randombobby", "passwd" => hash("sha1", "mdp"), "admin" => "0"));
$users[4] = serialize(array("login" => "jean-denis", "passwd" => hash("sha1", "saintdenis"), "admin" => "0"));
file_put_contents("private/passwd", serialize($users));
$prices = array("buchenoel" => "4", "buchechocolat" => "3", "buchefraise" => "4", "ckchocolat" => "6");
$prices2 = array("ckcaramel" => "5", "ckfraise" => "5", "annivanille" => "7", "anniframboise" => "8");
$prices3 = array("annichocolat" => "10");
$prices = array_merge($prices, $prices2, $prices3);
file_put_contents("private/prices", serialize($prices));
?>
