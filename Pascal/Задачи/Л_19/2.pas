//����18
uses crt;
const
  n=20;//����� ��������

//����������
var
a: array [1..n] of integer; // 2 �������
b: array [1..n] of integer;

i,max,index:integer;//������ ���������� ��� ����� ��������� �������
//max - ������������ �������
//index - ����� �����.��������
begin

randomize;
//������ ���������� �������
  for i:=1 to n do
  begin
    a[i]:=random(20);//��������� ��������� �����
    b[i]:=random(20);
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

//���� ������������ ������� � ������ �������
  max:=a[i];
  for i:=2 to n do
  begin
       if a[i]>max
       then
           max:=a[i];
  end;
  //�������
  writeln('');
  writeln('������������ ������� � ������� � = ',max);
  
//���� ������ ������������ �������� �� ������ �������
  max:=b[1];
  index:=1;
  for i:=2 to n do
  begin
       if b[i]<max
       then
       begin
           index:=i;
           max:=b[i];
       end;
  end;
  //�������
  writeln('������ ������������ �������� � ������� B = ',index);

  
readln;

end.
