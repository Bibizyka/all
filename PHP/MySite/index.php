
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" 
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head>
<meta http-equiv="Content-Type" content="text/html; charset="utf-8" />
<title>���������� ������� SuperSet.</title>
</head>

<?php
	session_start();
?>

<body>
	<table width=70% align="center" border=1 hight=50% bgcolor="grey">
		<tr hight=30%>
			<td width=15% bgcolor="grey">
      			<img src="images/suplogo.jpg"  width="200" height="180" alt="��� �������">
  			</td>
			<td width=57% bgcolor="grey">
				<img src="images/supersets-for-growth.jpg"  width="525" height="180" alt="��� �������">
   			</td>
			<td bgcolor="grey" align="center">
      				      				���������� ����������:<br>
					������ ��� 
					��<br>
					*9-b-rinat@rambler.ru<br>
					*vk.com/rrrinat<br>
   			</td>
		</tr>
	</table>	

	<table width=70% hight=30% align="center" bgcolor="#1E90FF">
		<tr>
			<td>
				<form action="testreg.php" method="post">
				
					<label>��� �����:</label>
					<input name="login" type="text" size="15" maxlength="15">
				 			
					<label>��� ������:</label>
					<input name="password" type="password" size="15" maxlength="15">
								
					<input type="submit" name="submit" value="�����">
					
										
				</form>
			</td>

			<td rowspan="2" width=20.5% align="center"><font><a href="reg.php">�����������</a></font></td>
		</tr>
		
		<tr>
			<td>
				<?php
					if (empty($_SESSION['login']) or empty($_SESSION['id']))
					{
						echo "�� ����� �� ����, ��� �����!  <a href='#'>��� ������  �������� ������ ������������������ �������������</a>";
					}
					else
					{
						echo "�� ����� �� ����, ��� ".$_SESSION['login']." <a href='indexForReg.php'>  ��� ������ �������� ������ ������������������ �������������</a>";
					}
				?>
			</td>
		</tr>
		
	</table>

	<table width=70% hight=30% align="center"  bgcolor="grey">
		<tr>
			<td>
				<img src="images/whey-pro4.jpg"  align="right" width="300" height="180" alt="������� SuperSet Whey Pro">
			
				�������������� �� ������������ ������, ������� ������������� ������� ������� � ������������� ��������, � ����� ��������� �������� ����������� ����� ������� ������.

50% �����!!! <br>
������ � ��������: 216 <br>
50% �����!!!<br><br>
������ � ��������: 216 <br>
����������� �������� (������ ������ 33 �): <br>
������������ 123 ����<br>
����� 16,5 �<br>
�������� 12,7 �<br>
���� 0,7 �<br>		
<br>		
�������� � �������������<br>		
<br>		
������� A 824 ��<br>		
������� E 2,5 ��<br>		
������� B1 0,32 ��<br>		
������� B2 0,32 ��<br>		
������� B6 1,25 ��<br>		
������� C 12,5 ��<br>		
����������� 3,88 ��<br>		
�������� ������� 25 ���<br>		
����� 6,25 ��<br>				
���������� ������� 2,5 ��<br>		
������� B12 3,1 ���<br>		
�������� ������� 0,5 ��<br>		
������ 6,23 ��<br>		
���� 0,74 ��<br>		
������� 0,12 ��<br>		
�������� 2,74 ��<br>		
���� 2,2 ��<br>				
������ 29,4 ��<br>		
<br>		
������������ �� ���������� Whey Pro:<br>		
��� ������������� ����� ������ ��������� ������� �������� 1 ������ ����� (33 �) ������� Whey Pro � 230-300 �� ����, ��������� ������ ��� ����.<br>		
<br>		
����������� Whey Pro:<br>		
<br>		
���������� ������������ ������ ������-�������������� (���-��), ��������������� ��������, ���������-����������� �������� 
(�������� ������, ������� ������, ����������� �����������, ����������� �������������, ��������������, ������������ �������, ���������� ������, �����������, �����, 
������� ����������, �������� �������, �������� �������, ������ �������, ���� �������, ����� ������,
�������� �������, �������� �������, ����� �������, ������ ������, ������ �������������, ������� �������), Guar Gum � ����������� ��� ������������� ������������.			
			</td>
			<td>
				<img src="images/banner.jpg"  width="185" height="400" alt="��� ������">
				<img src="images/banner.jpg"  width="185" height="400" alt="��� ������">
			</td>
		</tr>
		<tr>
    			<td align="center" bgcolor="grey">
				<br>
					<form action="proces.php" method="post">
						<table width="500" border="1">
							<tr bgcolor="#3300CC">
								<td width="250" style="color:#FFF">������������ ������</td>
								<td width="30" style="color:#FFF">����������</td>
							</tr>
							<tr>
								<td>SuperSet Whey Pro 7120�</td>
								<td><input name="supersetwheypro" type="text" size="4" maxlength="4"></td>
							</tr>
							
							<tr>
								<td>��� �� ������ �������� �����?</td>
								<td>
									<select name="find">
									<option value="a" selected>�� �����</option>
									<option value="b">���������� ���������</option>
									<option value="�">����� �� �����</option>
									<option value="d">���������</option>
									</select>
								</td>
							</tr>
							<tr>
								<td colspan="2" align="center"><input name="" type="submit" value="������� ������� �����"></td>
							</tr>
						</table>						
					</form>
					
					<br><br>
					
					<text align="center">
						�����������:
					</text>
					<br/>			
					<?php include("readBD.php"); ?>
					<br/>
						<form name="" action="addBD.php" method="post">
							<table>
								<tr> 
									<td> ���� ���:</td>
									<td> <input name="data[0]" type="text" value=""></td>
								</tr>
								<tr>
									<td>������� e-mail:</td>
									<td> <input name="data[1]" type="text" value=""> </td>
								</tr>
								<tr>
									<td> ����� ������ ���������:</td>
									<td> <textarea name="data[2]" rows=5 cols=20 wrap="off"></textarea> </td> 
								</tr>
							</table>
							<br>
								<input type="submit" name="add" value="�������� �����������">
							<br/>
						</form>
       			</td>
    			<td width=20%>
       				<img src="images/banner.jpg"  width="185" height="400" alt="��� ������">
				</td>
 		</tr>
	</table>
	<table width=70% hight=30% align="center">
		<tr>
    			<td colspan=3 align="center" bgcolor="#1E90FF">��������� �����  (�)<a href="#"><font color="#FFFFFF">����� �����������</font></a></td>
		</tr>
	</table>
	
	
	

</body>
</html>