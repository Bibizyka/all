uses crt;
const
  n=10;//����� �������
//����������
var
a: array [1..n] of integer;

i,min,k: integer;

begin

randomize;
//������ ���������� �������
  for i:=1 to n do
  begin
    //�������� ���������� �������
    a[i]:=random(20);
    //� ������� ������������
    write('a(', i, ')=', a[i], ' ') ;
  end;
  //��������� ������ ������� �� �����������
  min:=a[1]; k:=1;//k - ������ ������������

  for i:=2 to n do
  begin
    if a[i]<min then
    begin
      min:=a[i];
      k:=i;
    end;
  end;
  
  //����� ����������� - �������� ������,������� � ������� ������������
  for i:=k to n-1 do
    a[i]:=a[i+1];

  
  writeln('����� ������:');
  //�������
  for i:=1 to n-1 do
  begin
  write('a(', i, ')=', a[i], ' ') ;
  end;
readln;

end.
