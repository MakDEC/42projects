<?php
if ($_POST['number'] == 0 || !$_POST['number'])
	return ;
$file_array = unserialize(file_get_contents("private/stock"));
if (!$file_array[$_POST['element']])
	return ;
if ($number < 0)
{
	if ($file_array[$_POST['element']] < $_POST['number'])
		return ;
	$file_array[$_POST['element']] -= $_POST['number'];	
}
else
{
	$file_array[$_POST['element']] += $_POST['number'];
}
file_put_contents("private/stock", serialize($file_array));
?>
