<?php
function set_admin($login)
{
header("Location: index.html");
if (!file_exists("/Users/aanger/Desktop/PHP/day04/private/passwd"))
	return false;
$file_array = unserialize(file_get_contents("/Users/aanger/Desktop/PHP/day04/private/passwd"));
if ($file_array['login'])
{
	$file_array['admin'] = 1;
	file_put_contents("/Users/aanger/Desktop/PHP/day04/private/passwd", serialize($file_array));
	return true;

}
while ($file_array[$i])
{
	$temp = unserialize($file_array[$i]);
	if ($temp['login'] == $login)
	{
		$temp['admin'] = 1;
		break ;
	}
	$i++;
}
if (!$file_array[$i])
	return false;
$file_array[$i] = serialize($array);
file_put_contents("/Users/aanger/Desktop/PHP/day04/private/passwd", serialize($file_array));
return true;
}
?>
