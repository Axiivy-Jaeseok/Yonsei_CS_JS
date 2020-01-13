<?php

$conn = mysqli_connect('localhost', 'root', '2018147505', 'mysql');
$name = $_GET['P1'];

$sql = "SELECT NAME FROM ARTIST where name='$name'";
$result = mysqli_query($conn, $sql);
$row = mysqli_fetch_array($result);

$data ='';

if($row == null)
{
	$data= Array('Validity' => 'Valid');
}
else{
	$data= Array('Validity' => 'unValid', 'ErrorText' => ' inValid Artist Name');
}

header('Content-type: application/json');
echo json_encode( $data );
?>