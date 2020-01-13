<?php

$conn = mysqli_connect('localhost', 'root', '2018147505', 'mysql');

$title = urldecode($_GET['P1']);
$artist = urldecode($_GET['P2']);
$country = urldecode($_GET['P3']);
$company = urldecode($_GET['P4']);
$price = urldecode($_GET['P5']);
$year = urldecode($_GET['P6']);

$sql = "INSERT INTO CD VALUES (0,'$title', '$country', '$company', $price, $year);";
$sq3 = "INSERT INTO ARTIST VALUES (0, '$artist');";

$result = mysqli_query($conn, $sql);
$result2 = mysqli_query($conn, $sq3);

$data = [];
if(!$result){
	echo 'Error'.mysqli_error($conn);
}else{
	$sql2 = "SELECT * FROM ARTIST;";
	$result3 = mysqli_query($conn, $sql2);

	while($row = mysqli_fetch_array($result3))
	{
		$tmp= Array('NAME' => $row['NAME']);
		array_push($data , $tmp);
	}

}

header('Content-type: application/json');
echo json_encode( $data );
?>
