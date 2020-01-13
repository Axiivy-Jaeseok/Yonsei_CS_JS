<?php

$conn = mysqli_connect('localhost', 'root', '2018147505', 'mysql');

$sql = "SELECT * FROM ARTIST;";
$result = mysqli_query($conn, $sql);

$data= [];
while($row = mysqli_fetch_array($result))
{
	$tmp= Array('NAME' => $row['NAME']);
	array_push($data , $tmp);
}
header('Content-type: application/json');
echo json_encode( $data );
?>

