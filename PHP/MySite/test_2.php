
<?php
$link = mysql_connect("localhost", "root")
or die("�� ���� ������������" ); // ������� Primer ������� ����� ������
mysql_select_db('Primer', $link) or die ('�� ���� ������� ��');

$query = "INSERT INTO Tovar VALUES(100,'TV LG','20000')";

$result = mysql_query($query);
if($result) {echo "������ ������� � ���� ������";} else {echo "������, ������ �� ���� ������� � ��";}
mysql_close($link);
echo "<br/>";
?>

<?php
$link = mysql_connect("localhost", "root")
or die("�� ���� ������������" ); // ������� Primer ������� ����� ������
mysql_select_db('Primer', $link) or die ('�� ���� ������� ��');

$query = "INSERT INTO Tovar VALUES(101,'DVD','5000')";

$result = mysql_query($query);
if($result) {echo "������ ������� � ���� ������";} else {echo "������, ������ �� ���� ������� � ��";}
mysql_close($link);
echo "<br/>";
?>

<?php
$link = mysql_connect("localhost", "root")
or die("�� ���� ������������" ); // ������� Primer ������� ����� ������
mysql_select_db('Primer', $link) or die ('�� ���� ������� ��');

$query = "INSERT INTO Tovar VALUES(102,'Nokia','27000')";

$result = mysql_query($query);
if($result) {echo "������ ������� � ���� ������";} else {echo "������, ������ �� ���� ������� � ��";}
mysql_close($link);
echo "<br/>";
?>

<?php
$link = mysql_connect("localhost", "root")
or die("�� ���� ������������" ); // ������� Primer ������� ����� ������
mysql_select_db('Primer', $link) or die ('�� ���� ������� ��');

$query = "INSERT INTO Tovar VALUES(103,'Philips','15000')";

$result = mysql_query($query);
if($result) {echo "������ ������� � ���� ������";} else {echo "������, ������ �� ���� ������� � ��";}
mysql_close($link);
echo "<br/>";
?>



<?php
echo "<br/>    ����� �������� �����-����: <br/>";
$link = mysql_connect("localhost", "root")
or die("�� ���� ������������" ); // ������� Primer ������� ����� ������
mysql_select_db('Primer', $link) or die ('�� ���� ������� ��');

$query = "SELECT * FROM Tovar";
$result=mysql_query($query);

while($r=mysql_fetch_array($result)) {
echo "$r[model] - $r[price]<br/>";
}
mysql_close($link);
?>


<?php
$link = mysql_connect("localhost", "root")
or die("�� ���� ������������" ); // ������� Primer ������� ����� ������
mysql_select_db('Primer', $link) or die ('�� ���� ������� ��');

echo "<br/>    ����� �������� �����-����(������ 10 �����): <br/>";
$query = "SELECT * FROM Tovar WHERE price>10000";
$result=mysql_query($query);

while($r=mysql_fetch_array($result)) {
echo "$r[model] - $r[price]<br/>";
}
mysql_close($link);
?>
