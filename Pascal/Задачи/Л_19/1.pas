//����19
uses crt;
const
  n=20;//����� ��������

//����������
var
ar: array [1..n] of integer; // ������

i,A,B:integer;//i - ������ ���������� ��� ����� ��������� �������

begin

//������ ����� � � �
writeln('������� �=');
readln(A);

writeln('������� B=');
readln(B);

randomize;
//������ ���������� �������
  for i:=1 to n do
  begin
    //�������� ���������� ������� �� -20 �� 20
    ar[i]:=random(10)-random(15);//��������� ��������� �����
  end;


  writeln('������ :');
  //������� ������ ������ �
  for i:=1 to n do
  begin
  write(ar[i], ' ') ;
  end;

//������ ��������� �� ������� ������ - � ������ �������� ���������� �, � �������� - B
//������������ ��������
writeln('');
  writeln('����� ������ :');
  for i:=1 to n do
  begin
  if i mod 2=0
     then ar[i]:=ar[i]+A
     else ar[i]:=ar[i]+B;
  write(ar[i], ' ') ;
  end;

readln;

end.
