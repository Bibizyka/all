<?php
//������� �������� ����� ����������
$supersetwheypro = $_POST['supersetwheypro'];
?>

<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=windows-1251">
<title>���������� ������</title>
</head>


<body>
<h2>�������� ��������</h2>
<h3>���������� ������</h3>

<?php
	echo "<p>����� ��������� � ";
	echo date('H:i, j F');
	echo "</p>";
	echo "<p>������ ������ ������:</p>";
	echo "$supersetwheypro - SuperSet Whey Pro <br>"; /* ���, ������ ���������� */
	
	
	$total = 0;
	$total = $supersetwheypro;
	echo '�������� �������: '.$total. '<br><br>';
	
/* ���������� �������� - ���� */
	define ('SUPERSETWHEYPRO_PRICE', 2630);
	
	$totalamount = 0.00;
	$totalamount = $supersetwheypro*SUPERSETWHEYPRO_PRICE;

//����� ���� �������
	echo '�����: '.number_format($totalamount,2). ' RUB<br><br>';

/* ����� �������� �������� �� ����� */
	echo SUPERSETWHEYPRO_PRICE. " ���. - ��������� 1 ����� �������� SuperSet Whey Pro.<br>";

?>
</body>
</html>

