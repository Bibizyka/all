
uses crt;

//���������� ��� ������ � ������ �������
var A3,B3,C3:file of integer;
    n, a, sumPol, kolNul:integer; //sumPol - ����� �������������, kolNul - ���������� �������, a - ���������� , n - ���������� �����

begin

assign(A3,'A3');
rewrite(A3);
assign(B3,'B3');
rewrite(B3);
assign(C3,'C3');
rewrite(C3);

//������� ����� ����� �������?
Writeln('���������� ����-����� = ');
readln(n);

//������ ����� �����. ��������� - ����
writeln('������� � ���� ����� �����, ��������� ����� ����:');
repeat
      readln(a);
      write(A3,a);{�������� A �����}
      n:=n-1;
until n=0;

writeln('���������� ��������� �����:');
reset(A3);//��������� �� ������

while not eof(A3) do   //��������� � A �����,���� �� ������ �� ��� �����
 begin
  read(A3,a);
  write(a,' ');
  if a > 0 then sumPol:=sumPol+a
  else
      if a = 0 then kolNul:=kolNul+1;
  
 end;

writeln;
close(A3);//��������� A
//���������� ����� ������������� ����� � ���� B
write(B3,sumPol);
//����������  ���������� ������� - � ���� �
write(C3,kolNul);

//������� �� ����� ���������� ����������
//
writeln('���������� ������� �����(B):');
reset(B3);
  read(B3,a);
  write(a,' ');
writeln;
close(B3);

writeln('���������� �������� �����(C):');
reset(C3);
  read(C3,a);
  write(a,' ');
writeln;
close(C3);

readln;
end.
