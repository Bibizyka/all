
uses crt;
var
A,B,kol,kolN,i,j,N: integer; //kol, kolN - ������������� �������(�������� ���������), N - �������� �����

begin
  writeln('������� A');
  readln(A);

  writeln('������� B');
  readln(B);

  //���� ����� N
  //����� ��������� ����� ������� ����� = 0
  kolN:=0;
  //���� A>B(�������� �����,��������)
  if A>B
  then
  begin
      N:=A;
      for i:=A downto B do
      begin
           kol:=0;
           //������� ���������� ��������� ��� ������� �����
           for j:=1 to i-1 do
           begin
                //���� �������� ��������� - ���������� ������� ���������
                if i mod j=0
                then kol:=kol+1
                     else;
                //���� ���������� ��������� � ����� ������,��� � ���������� - ���������� ��� �����
                if kol>kolN
                then
                   begin
                         kolN:=kol;
                         N:=i;
                   end
           end;
      end
  end
  
  else
  
  begin
      N:=B;
      for i:=A to B do
      begin
           kol:=0;
           //������� ���������� ��������� ��� ������� �����
           for j:=1 to i-1 do
           begin
                //���� �������� ��������� - ���������� ������� ���������
                if i mod j=0
                then kol:=kol+1
                     else;
                //���� ���������� ��������� � ����� ������,��� � ���������� - ���������� ��� �����
                if kol>kolN
                then
                   begin
                         kolN:=kol;
                         N:=i;
                   end
           end;
      end;
  end;

  //�������
  writeln('�����,� ���������� ����������� ��������� = ',N);

readln;

end.
