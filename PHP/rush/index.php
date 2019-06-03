<?php session_start(); ?>
<!DOCTYPE html>
<html>
	<head>
		<link rel="stylesheet" type="text/css" href="login.css">
	</head>
<body>
<?php
$data = $_SERVER['QUERY_STRING'];
$img1 = "https://www.enviedebienmanger.fr/sites/default/files/cheesecake_coulis_fraise_0.png";
$img2 = "https://images.marmitoncdn.org/recipephotos/multiphoto/df/df8e862d-7094-4450-8ef9-86b964526ef8_normal.jpg";
$img3 = "https://www.196flavors.com/wp-content/uploads/2015/12/buche-de-noel-1.jpg";
$to1 = "ckfraise.php";
$to2 = "anniframboise.php";
$to3 = "buchenoel.php";
switch ($data) {
case "cat=anniv":
	$img1 = "http://a53.idata.over-blog.com/600x400/2/55/25/84/Desserts-2012/gateaualbert1.jpg";
	$img2 = "https://images.marmitoncdn.org/recipephotos/multiphoto/df/df8e862d-7094-4450-8ef9-86b964526ef8_normal.jpg";
	$img3 = "https://cac.img.pmdstatic.net/fit/http.3A.2F.2Fprd2-bone-image.2Es3-website-eu-west-1.2Eamazonaws.2Ecom.2Fcac.2F2018.2F09.2F25.2Fd47d09a0-ab2d-439d-8996-7123c5e5af23.2Ejpeg/326x326/quality/80/crop-from/center/gateau-d-anniversaire-vanille.jpeg";  
	$to1 = "annichocolat.php";
	$to2 = "anniframboise.php";
	$to3 = "annivanille.php";
	break;
case "cat=buche":
	$img1 = "https://www.196flavors.com/wp-content/uploads/2015/12/buche-de-noel-1.jpg";
	$img2 = "https://files.meilleurduchef.com/mdc/photo/recette/buche-chocolat-creme-brulee/buche-chocolat-creme-brulee-640.jpg";
	$img3 = "https://files.meilleurduchef.com/mdc/photo/recette/buche-fraises-champagne/buche-fraises-champagne-640.jpg";
	$to1 = "buchenoel.php";
	$to2 = "buchechocolat.php";
	$to3 = "buchefraise.php";
	break;
case "cat=choco":
	$img1 = "https://files.meilleurduchef.com/mdc/photo/recette/buche-chocolat-creme-brulee/buche-chocolat-creme-brulee-640.jpg";
	$img2 = "https://static.cuisineaz.com/610x610/i22434-cheesecake-au-cafe-sauces-chocolat-et-caramel.jpg";
	$img3 = "http://a53.idata.over-blog.com/600x400/2/55/25/84/Desserts-2012/gateaualbert1.jpg";
	$to1 = "buchechocolat.php";
	$to2 = "ckchocolat.php";
	$to3 = "annichocolat.php";
	break;
case "cat=cheese":
	$img1 = "https://static.cuisineaz.com/610x610/i22434-cheesecake-au-cafe-sauces-chocolat-et-caramel.jpg";
	$img2 = "https://www.enviedebienmanger.fr/sites/default/files/cheesecake_coulis_fraise_0.png";
	$img3 = "http://www.lesfoodies.com/_recipeimage/33815/cheesecake-au-caramel-beurre-sale.jpg";
	$to1 = "ckchocolat.php";
	$to2 = "ckfraise.php";
	$to3 = "ckcaramel.php";
	break;
case "cat=selec":
	$img1 = "https://www.enviedebienmanger.fr/sites/default/files/cheesecake_coulis_fraise_0.png";
	$img2 = "https://images.marmitoncdn.org/recipephotos/multiphoto/df/df8e862d-7094-4450-8ef9-86b964526ef8_normal.jpg";
	$img3 = "https://www.196flavors.com/wp-content/uploads/2015/12/buche-de-noel-1.jpg";
	$to1 = "ckfraise.php";
	$to2 = "anniframboise.php";
	$to3 = "buchenoel.php";
	break;
}
$co_deco = "se connecter";
$lien = "login.html";
$en_stock1 = "";
$en_stock2 = "";
$en_stock3 = "";
	/*rajouter la fonction qui check si il reste des stocks
	if (!sotck(prod1))*/
//    $en_stock1 = "desolé, le produit n'est plus dispo";
/*if (!stock(prod2))*/
//  $en_stock2 = "desolé, le produit n'est plus dispo";
/*if (!stock(prod3))*/
//$en_stock3 = "";
if ($_SESSION['login']) {
	$co_deco = "se deconnecter";
	$lien = "logout.php";
}

?>
		<a href=<?php echo $lien ?>><button class="butt"><?php echo $co_deco ?></button></a>
		<a href="panier.php"><button class="butt">mon panier</button></a>
		<?php if ($_SESSION['login'] == "admin") :?> 
		<a href="admin_page.html"><button class="butt">admin</button></a>
	<?php endif; ?>
		<div class="dropdown">
		<button class="dropbtn"></button>
		<div class="dropdown-content">
		</div>
		</div>
		<div class="dropdown">
		<button class="dropbtn">categories</button>
				<div class="dropdown-content">
					<a href="index.php?cat=buche" action="index.php">buche</a>
					<a href="index.php?cat=choco" action="index.php">chocolat</a>
					<a href="index.php?cat=cheese" action="index.php">cheesecake</a>
					<a href="index.php?cat=anniv" action="index.php">anniversaire</a>
					<a href="index.php?cat=selec" action="index.php">notre selection</a>
				</div>
		</div>
	</br>
	<p class="bonjour">bonjour <?php echo $_SESSION['login'] ?></p>
	<div class="main">
		<span class="prod"><p class="no_stock"><?php echo $en_stock1 ?></p><img class="article" src=<?php echo $img1 ?>>
		<a href=<?php echo $to1 ?>><button><img class="panier" src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRPO5hIB1VSeGS0YIohVrnYaFXklsGdEGv3D2Fycj8lK8XK9w5L"></button></a></span>
		<span class="prod"><p class="no_stock"><?php echo $en_stock2 ?></p><img class="article" src=<?php echo $img2 ?>>
		<a href=<?php echo $to2 ?>><button><img class="panier" src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRPO5hIB1VSeGS0YIohVrnYaFXklsGdEGv3D2Fycj8lK8XK9w5L"></button></a></span>
		<span class="prod"><p class="no_stock"><?php echo $en_stock3 ?></p><img class="article" src=<?php echo $img3 ?>>
		<a href=<?php echo $to3 ?>><button><img class="panier" src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRPO5hIB1VSeGS0YIohVrnYaFXklsGdEGv3D2Fycj8lK8XK9w5L"></button></a></span>
	</div>
</body>
</html>
