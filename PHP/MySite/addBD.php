<?php
$name=strip_tags(stripslashes(substr($_POST['data']['0'],0,20)));
$mail=strip_tags(stripslashes(substr($_POST['data']['1'],0,30)));
$text=strip_tags(stripslashes(substr($_POST['data']['2'],0,300)));

if($_POST['add'] != '') {
    if($name != '') {
        if($mail !='') {
            if($text != '') {

//������������ � ��.
$db=@mysql_connect("localhost", "root", "") or die("������ �����������");
@mysql_select_db("Primer", $db) or die("�� ���� ������� ��");
@mysql_query("SET NAMES UTF-8");
$query = "INSERT INTO gbook VALUES (NULL,
'".$name."',
'".$mail."',
'".$text."')";
if(mysql_query($query)) { echo "������ <br/><a href=\"index.php\">���������</a>";}
 else {echo "������ ������";};
 }
 else {echo "������� �����������";}
 }
 else {echo "������� e-mail";}
 }
 else {
 echo "������� ���";
 }
 }
 else {echo "<a href=\"index.php\">�����</a>";  };
?>
