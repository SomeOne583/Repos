<?php
$servername = "localhost";
$username = "577441_user";
$password = "577441";
$dbname = "BD1_577441";

// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbname);

if (!$conn) {
        die("Connection failed: " . mysqli_connect_error());
}

$sql = 'UPDATE services SET cant = ' . $_POST["cant"] . ' WHERE id = ' . $_POST["id"] . ';';
mysqli_query($conn, $sql);

mysqli_close($conn);
?>
