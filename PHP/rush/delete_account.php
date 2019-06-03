#!/usr/bin/php
<?php
function delete_account($login)
{
	$first_array = unserialize(file_get_contents("private/passwd"));
	$i = 0;
	echo "on cherche : ";
	echo $login;
	echo "\n";
	/*while ($first_array[$i])
	{
		$temp = unserialize($first_array[$i]);
		print_r($temp);
		if ($temp['login'] != $login)
			$new_tab[$i] = $first_array[$i];
		$i++;
	}*/
	foreach ($first_array as $key => $value)
	{
		$temp = unserialize($first_array[$i]);
		print_r($temp);
		if ($temp['login'] != $login)
			$new_tab[$i] = $first_array[$i];
		$i++;
	
	}
	if ($new_tab != NULL)
		file_put_contents("private/passwd", serialize($new_tab));
	else
		file_put_contents("private/passwd", "");	
}
delete_account("bob");
?>
