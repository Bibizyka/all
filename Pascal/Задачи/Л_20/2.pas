uses crt;
const
  n=20;//����� �������
//����������
var
a: array [1..n] of integer;

i,min,max,buf: integer;//min, max - ������� �������������� ����������� � ������������ ���������,
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
  
  //��������� ������ ������� �� ����������� � ������������
  min:=1;
  max:=1;
  
  for i:=2 to n do
  begin
    if a[i]<a[min] then
    begin
      min:=i;
      buf:=i;
    end;
    
    if a[i]>a[max] then
    begin
      max:=i;
      buf:=i;
    end;
  end;

  //������ ������� ����������� � ������������ ��������
  buf:=a[min];
  a[min]:=a[max];
  a[max]:=buf;

  writeln('����� ������:');
  //�������
  for i:=1 to n do
  begin
  write(a[i], ' ') ;
  end;
readln;

end.
