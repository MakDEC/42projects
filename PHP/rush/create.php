<?php
if (create_account($_POST['login'], $_POST['passwd']) == true)
	header("Location: index.php");
else
	header("Location: create2.html");

function create_account($login, $passwd)
{
	if ($login == "" || $passwd  == "")
		return false;
	$file_exist = 0;
	if (!file_exists("private"))
		mkdir("private");
	if (file_exists("private/passwd"))
		$file_exist = 1;
	$array['login']  = $login;
	$array['passwd']  = hash("sha1", $passwd);
	$array['admin'] = 0;
	if ($file_exist == 1)
	{
		$file_array = unserialize(file_get_contents("private/passwd"));
		if ($file_array['login'])
		{
			if ($file_array['login'] == $array['login'])
				return false;
			else
			{
				$file_array2[0] = serialize($file_array);
				$file_array2[1] = serialize($array);
				file_put_contents("private/passwd", serialize($file_array2));
				return true;
			}
		}
		while ($file_array[$i] != NULL)
		{
			$temp = unserialize($file_array[$i]);
			if ($temp['login'] == $array['login'])
				return false;
			$i++;
		}
		$file_array[$i] = serialize($array);
		file_put_contents("private/passwd", serialize($file_array));
	}
	else
		file_put_contents("private/passwd", serialize($array));
	return true;
}
?>
