
uses crt;
//���������� ��� ������ � ������ �������
var A2,B2:file of integer;
    a:integer; //a - ���������� ��� ���������(������ ��� �������� �� �� �����)
    
begin

assign(A2,'A2');
rewrite(A2);
assign(B2,'B2');
rewrite(B2);

//������ ����� �����. ��������� - ����
writeln('������� � ���� ����� �����, ��������� ����� ����:');
repeat
      readln(a);
      write(A2,a);{�������� A �����}
until a=0;

writeln('���������� ��������� �����:');
reset(A2);

while not eof(A2) do   //��������� � A �����,���� �� ������ �� ��� �����
 begin
  read(A2,a);
  write(a,' ');
  if a mod 2=0 then write(B2,a){�������� B �����}
 end;

writeln;
close(A2);//��������� A
reset(B2);

//������� �� ����� - ��� �� �������� �� �� ������ ����?
writeln('���������� ������� �����:');
reset(B2);

while not eof(B2) do
 begin
  read(B2,a);
  write(a,' ');
 end;
writeln;
close(B2);

readln;
end.
