uses crt;
const
  n=10;//����� �������
//����������
var
a: array [1..n] of integer;

i,j,k: integer; // k - ������� �����,������������ �� �������� ��������

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

  //������� �������� ������� - �������� ������
  k:=0;
  for i:=1 to n do
  begin

       if i mod 2=1
       then
       begin
           for j:=i-k to n-k-1 do
           begin
                a[j]:=a[j+1];
           end;
           k:=k+1;
       end;
  end;
  
      //�������
       writeln('����� ������:');
       for i:=1 to n-k do
       write('a(', i, ')=', a[i], ' ') ;

readln;

end.
