uses crt;
const
  n=10;//����� �������
//����������
var
a: array [1..n] of integer;

i,buf,j,g: integer; //buf, j - �������������� ����������,����� ������ ������� �������� �������

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
  for i:=2 to n do
  begin
       buf:=A[i];
       j:=1;
       //����������� �������� �� �������� ������!
       while ((buf<a[j])) do
             Inc(j);
       for g:=i-1 downto j do
           //������� �� ���������� �������:
           if j mod 2=1
           then
             a[g+1]:=a[g];
       a[j]:=buf;
  end;

  writeln('����� ��������������� ������:');
  //�������
  for i:=1 to n do
  begin
  write('a(', i, ')=', a[i], ' ') ;
  end;
readln;

end.
