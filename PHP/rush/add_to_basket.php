<?php
function add_to_basket($element)
{
	session_start();
	if (!file_exists("private/stock"))
		return ;
	$stock_array = unserialize(file_get_contents("private/stock"));
	if (!$stock_array[$element])
		return ;
	if ($stock_array[$element] < 1)
		return -1;
	$stock_array[$element] -= 1;
	file_put_contents("private/stock", serialize($stock_array));
	if (!$_SESSION['panier'])
	{
		$_SESSION['panier'] = $element . ":" . "1";
		$stock_array[$element] -= 1;
		return ;
	}
	$split_panier = explode(";", $_SESSION['panier']);
	$modified = 0;
	foreach ($split_panier as $key => $value)
	{
		$temp = explode(":", $value);
		if ($temp[0] == $element)
		{
			$temp[1] += 1;
			$temp_up = $temp[0] . ":" . $temp[1];
			$new_pan .= ";" . $temp_up;
			$modified = 1;
		}
		$new_pan .= $value;
		$i++;
	}
	if ($modified == 0)
		$new_pan = $_SESSION['panier'] . ";" . $element . ":" . "1";
	$_SESSION['panier'] = $new_pan;
}
?>
