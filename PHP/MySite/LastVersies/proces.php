<?php
//������� �������� ����� ����������
$shoco = $_POST['shoco'];
$orehy = $_POST['orehy'];
$fruct = $_POST['fruct'];
?>

<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=windows-1251">
<title>�������� ��������. ���������� ������</title>
</head>


<body>
<h2>�������� ��������</h2>
<h3>���������� ������</h3>

<?php
	echo "<p>����� ��������� � ";
	echo date('H:i, j F');
	echo "</p>";
	echo "<p>������ ������ ������:</p>";
	echo "$shoco - ���������� ������� <br>"; /* ���, ������ ���������� */
   /* echo $shoco. " - ���������� ������� <br>";   */
	echo $orehy. " - ����� � ��������<br>";
	echo $fruct. " - ���������� <br>";
	
	
	$total = 0;
	$total = $shoco + $orehy + $fruct;
	echo '�������� �������: '.$total. '<br><br>';
	
/* ���������� �������� - ���� */
	define ('SHOCO_PRICE', 50);
	define ('OREHY_PRICE', 70);
	define ('FRUCT_PRICE', 40);

	$totalamount = 0.00;
	$totalamount = $shoco*SHOCO_PRICE + $orehy*OREHY_PRICE + $fruct*FRUCT_PRICE;

//����� ���� �������
	echo '�����: '.number_format($totalamount,2). ' RUB<br><br>';

	$ndc = 0.18; //����� ��� ���������� 18% - ������������ �������� ��� ���.
	$totalamount = $totalamount * (1 + $ndc);

	echo '�����, ������� ���: '.$totalamount. ' RUB<br><br>';

/* ����� �������� �������� �� ����� */
	echo SHOCO_PRICE. " ���. - ��������� 1 �� ���������� ������.<br>";
	echo OREHY_PRICE. " ���. - ��������� 1 �� ������ � ��������.<br>";
	echo FRUCT_PRICE. " ���. - ��������� 1 �� �����������.";

?>
</body>
</html>

