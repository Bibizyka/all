
uses crt;

const
n=20;
//���������� ��� ����� � ������ �������
var f:file of integer;
    i,j,buf,s:integer; //buf - ��� ������ � ������(������-������ ���������)
    a: array [1..n] of integer; // 2 �������
    b: array [1..n] of integer;
begin

assign(f,'file');
rewrite(f);

//������ ����� �����. ��������� - ����
writeln('������� � ���� ����� �����, ��������� ����� ����:');
repeat
      readln(buf);
      write(f,buf);{�������� A �����}
      s:=s+1;
until buf=0;

//���������� ������ ����� ������� �� �����
writeln('���������� ��������� �����:');
reset(f);

i:=1;
j:=1;
while not eof(f) do   //��������� � A �����,���� �� ������ �� ��� �����
 begin
  read(f,buf);
  write(buf,' ');
  //� ������������ �������� � ���� ������� (����� �� 2 �����!)
  if (i<(s div 2))
     then
         begin
          a[i]:=buf; i:=i+1;
         end
     else
         begin
          b[j]:=buf; j:=j+1;
         end
     
 end;

close(f);//��������� ����

//�������� ��� ���������� �������

  writeln('������ �1(�):');
  //������� ������ ������ �
  for i:=1 to i-1 do
  begin
  write(a[i], ' ') ;
  end;

  writeln(' ');
  writeln('������ �2(�):');
  //������� ������ ������ �
  for i:=1 to j-1 do
  begin
  write(b[i], ' ') ;
  end;

readln;
end.
