//����18
uses crt;
const
  n=20;//����� ��������
  
//����������
var
a: array [1..n] of integer; // 2 �������
b: array [1..n] of integer;

i:integer;//������ ���������� ��� ����� ��������� �������

begin

randomize;
//������ ���������� �������
  for i:=1 to n do
  begin
    //�������� ���������� ������� �� -20 �� 20
    a[i]:=random(20)-random(40);//��������� ��������� �����
    b[i]:=random(20)-random(40);
  end;


  writeln('������ �1(�):');
  //������� ������ ������ �
  for i:=1 to n do
  begin
  write(a[i], ' ') ;
  end;

  writeln(' ');
  writeln('������ �2(�):');
  //������� ������ ������ �
  for i:=1 to n do
  begin
  write(b[i], ' ') ;
  end;
  
  
readln;

end.
