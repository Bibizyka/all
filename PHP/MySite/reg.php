
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

	<table width=70% hight=30%  align="center" bgcolor="#1E90FF">
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

	<table width=70% hight=30% align="center" border=1 bgcolor="grey">
		<tr align="center">
			<td>
    			<form action="save_user.php" method="post">
						<a align="center" font color="black" > �����������: </a>
						
						<p>
							<label>���:<br></label>
								<input name="name1" size="15" maxlength="15">
						</p>
						<p>
							<label>�������:<br></label>
								<input name="surname" size="15" maxlength="15">
						</p>
						<p>
							<label>����:<br></label>
								<SELECT NAME="Day"> 
								<OPTION value="1"> 1
								<OPTION value="2"> 2
								<OPTION value="3"> 3
								<OPTION value="4"> 4
								<OPTION value="5"> 5
								</SELECT>
						</p>
						<p>
							<label>�����:<br></label>
								<SELECT NAME="Month">
								<OPTION value="January" > ������
								<OPTION value="February" > �������
								<OPTION value="March" > ����
								<OPTION value="April" > ������
								<OPTION value="May" > ���
								</SELECT>
						</p>
						<p>
							<label>������� ���:<br></label>
								<INPUT TYPE="radio" NAME="m" VALUE="men"> �������<BR>
								<INPUT TYPE="radio" NAME="f" VALUE="female"> �������<BR>
						</p>
						<p>
							<label>���:<br></label>
								<INPUT NAME="cod"> <BR>
						</p>
						<p>
							<label>�������:<br></label>
								<INPUT NAME="phone" SIZE="12" MAXLENGTH="6" ><BR>
						</p>
						<p>
							<label>�����:<br></label>
								<TEXTAREA NAME="adress" COLS=32 ROWS=4>
								�������
								���������
								��.��������, 99
								</TEXTAREA>
						</p>
						<p>
							<label>���:<br></label>
								<INPUT NAME="cod"> <BR>
						</p>
					
						<!-- save_user.php - ��� ����� �����������. �� ����, ����� ������� �� ������ "������������������", ������ �� �����  ���������� �� ��������� save_user.php ������� "post" -->
						<p>
							<label>��� �����:<br></label>
								<input name="login" type="text" size="15" maxlength="15">
						</p>
						<!-- � ��������� ���� (name="login" type="text") ������������ ������ ���� �����  -->
						<p>
							<label>��� ������:<br></label>
								<input name="password" type="password" size="15" maxlength="15">
						</p>
						<!-- � ���� ��� ������� (name="password" type="password") ������������ ������ ���� ������ --> 
						<p>
							<input type="submit" name="submit" value="������������������">
						<!--������ (type="submit") ���������� ������ �� ��������� save_user.php--> 
						</p>
					</form>
				</td>
    			<td width=20%>
       				<img src="images/banner.jpg"  width="185" height="400" alt="��� ������">
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