<?php
header("Location: index.php");
session_start();
$_SESSION = "";
session_destroy();
?>
