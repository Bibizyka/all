uses crt;
//����������
var
chislo, cifra, kol,p: integer; //�����, ����� � ���������� ��� , p - ���������� ��� ����������� �� ����� ����.

begin
  writeln('������� �����:');
  readln(chislo);

  writeln('������� �����:');
  readln(cifra);
  
  //������� ���������� ���
  while (chislo>0)do
  begin
       p:=chislo mod 10;
       chislo:= chislo div 10;

       if p=cifra
       then kol:=kol+1;
  end;

  
  //�������
  writeln('����������� ���������� ���:',kol);
  
readln;

end.
