
<?php
$link = mysql_connect("localhost", "root")
or die("�� ���� ������������");
print ("���������� ���������");
mysql_close($link);
?>

<?php
$link = mysql_connect("localhost", "root")//���������� ������ Root -> root �����������!
or die("�� ���� ������������ � ����" );
// ������� Primer ������� ����� ������
mysql_select_db('Primer', $link) or die ('�� ���� ������� ��');
?>