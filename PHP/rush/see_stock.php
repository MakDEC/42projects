#!/usr/bin/php
<?php

echo "on passe par la\n";
if (!file_exists("private/stock"))
	return ;
$file_array = unserialize(file_get_contents("private/stock"));
print_r($file_array);

?>
