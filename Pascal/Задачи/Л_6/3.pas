uses crt;
//����������
var
chislo, fact: integer; //fact - ��������� �����

begin
  writeln('������� �����:');
  readln(chislo);
  
  //���������� �������
  fact:=chislo;
  //������� ���������/ ���������� �� ����� �� �������� ���� �� �����
  while (chislo>1)do
  begin
       chislo:= chislo - 1;
       fact:=chislo*fact;
  end;


  //�������
  writeln('��������� = ',fact);

readln;

end.
