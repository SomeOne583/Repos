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

$result = mysqli_query($conn, "SELECT * FROM services;");

echo '{"servicios":[';
for ($i = 0; $i < 5; $i++) {
	$row = mysqli_fetch_assoc($result);
	echo '{"id":"' . $row["id"] . '","nombre":"' . $row["nombre"] . '","descripcion":"' . $row["descripcion"] . '","img":"' . $row["img"] . '","cant":"' . $row["cant"] . '"}';
	if ($i < 4) {
		echo ",";
	}
}
echo "]}";

mysqli_close($conn);
?>
