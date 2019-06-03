<?php
session_start();
if (auth($_POST['login'], $_POST['passwd']) == true)
	header("Location: index.php");
else
	header("Location: login_no.html");
function auth($login, $passwd)
{
	if (!file_exists("private/passwd"))
		return FALSE;
	$hashed_passwd = hash("sha1", $passwd);
	$file_array = unserialize(file_get_contents("private/passwd"));
	if ($file_array['login'] && $file_array['login'] == $login && $file_array['passwd'] == $hashed_passwd)
	{
		$_SESSION['login'] = $login;
		return true;
	}
	foreach ($file_array as $key => $value)
	{
		$temp = unserialize($file_array[$key]);
		if ($temp['login'] == $login)
		{
			if ($temp['passwd'] == $hashed_passwd)
			{
				$_SESSION['login'] = $login;
				return TRUE;
			}
			else
				return FALSE;
		}
		$i++;
	}
	return FALSE;
}
?>
