#!/usr/bin/php
<?php
function see_all_users()
{
	if (!file_exists("private/passwd"))
	{
		echo "pas de fichier\n";
		return ;
	}
	$file_array = unserialize(file_get_contents("private/passwd"));
	if ($file_array == false)
		echo "return false\n";
	$i = 0;
	if ($file_array['login'])
	{
		print_r($file_array);
	}
	/*while ($file_array[$i])
	{
		$temp = unserialize($file_array[$i]);
		print_r($temp);
		$i++;
	}*/
	foreach ($first_array[$i] as $key => $value)
	{
		$temp = unserialize($first_array[$i]);
		print_r($temp);
		if ($temp['login'] != $login)
			$new_tab[$i] = $first_array[$i];
		$i++;

	}
	echo "check2\n";
}
see_all_users();
?>
