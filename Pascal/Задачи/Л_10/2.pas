uses crt;
//���������� - ������� �������������� � ������ ������������� �������� ��� ��������
var
Ax,Bx,Ay,By: integer; //s - �����,������� ����� ������� , x � y - ���������� ������
s: real;
begin
  writeln('������� ���������� ����� A');
  writeln('Ax=');
  readln(Ax);
  writeln('Ay=');
  readln(Ay);
  
  writeln('������� ���������� ����� B');
  writeln('B�=');
  readln(Bx);
  writeln('By=');
  readln(By);

  //������� ����� S: power(1,2) - �������� ����� 1 � ������� 2
  s:=sqrt(power((Ax-Bx),2)+power((Ay-By),2)); //sqrt - ����� ������ �� �����


  //�������
  writeln('����� = ',s);

readln;

end.
