uses crt;
const
  n=10;//����� �������
//����������
var
a: array [1..n] of integer;

i,buf,j: integer; //buf, j - �������������� ����������,����� ������ ������� �������� ������� ������� ������� �������

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
  //���������
  j:=0;
  while j<=n do
      begin
      for i:=4 to n do
          //�� ������������� � ������� � ������ �������
          if (i mod 2=0) and (a[i]>a[i-2]) then
             begin
             //������ �������
             buf:=a[i];
             a[i]:=a[i-2];
             a[i-2]:=buf;
             end;
      inc(j);
      end;

  writeln('����� ��������������� ������:');
  //�������
  for i:=1 to n do
  begin
  write('a(', i, ')=', a[i], ' ') ;
  end;
readln;

end.
