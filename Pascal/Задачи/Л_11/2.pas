uses crt;
var
N,i: integer; //N - ����� ��������,�� ���������� �������
s: string;

begin
  writeln('������� ������������ ������');
  readln(s);

  N:=0;
  
  for i:=1 to length(s)  do
  begin
    //���� ��� ������� �� ������ �� 0 �� 9 - �� ������,��� ��� "�����". ������ - ����������� ������� �� �������.
    if ((s[i]<'0') or (s[i]>'9'))
    then N:=N+1;
    
  end;

  //�������
  writeln('���������� ������ N = ',N);

readln;

end.
