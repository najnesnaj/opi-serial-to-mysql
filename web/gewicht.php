<?php
include("phpgraphlib.php");
$graph=new PHPGraphLib(550,350); 
$link = mysql_connect('localhost', 'stm8', 'stm8')
   or die('Could not connect: ' . mysql_error());
     
mysql_select_db('metingen') or die('Could not select database');
  
$dataArray=array();
  
//get data from database
$sql="SELECT gewicht, datum AS 'count' FROM gewicht group by gewicht";
$result = mysql_query($sql) or die('Query failed: ' . mysql_error());
if ($result) {
  while ($row = mysql_fetch_assoc($result)) {
      $salesgroup=$row["gewicht"];
      $count=$row["count"];
      //add to data array
      $dataArray[$count]=$salesgroup;
  }
}
  
//configure graph
$graph->addData($dataArray);
$graph->setTitle("Sales by Group");
$graph->setGradient("lime", "green");
$graph->setBarOutlineColor("black");
$graph->createGraph();
?>
