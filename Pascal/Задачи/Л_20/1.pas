uses crt;
const
  n=20;//����� �������
//����������
var
a: array [1..n] of integer;

i,buf: integer;
//buf - ��� ������

begin

randomize;
//������ ���������� �������
  for i:=1 to n do
  begin
    //�������� ���������� �������
    a[i]:=random(20);
    //� ������� ������������
    write(a[i], ' ') ;
  end;

  //������ ������� ������ � ��������� ��������
  buf:=a[1];
  a[1]:=a[n];
  a[n]:=buf;

  writeln('����� ������:');
  //�������
  for i:=1 to n do
  begin
  write(a[i], ' ') ;
  end;
readln;

end.
