uses crt;
const
  n=10;//����� �������
//����������
var
a: array [1..n] of integer;

i,kol,k,j,buf: integer;    //buf - ��� ������

begin

randomize;
//������ ���������� �������
  for i:=1 to n do
  begin
    //�������� ���������� �������
    a[i]:=random(20)-random(20);
    //� ������� ������������
    write('a(', i, ')=', a[i], ' ') ;
  end;
  
  //���������
  kol:=i-1;
  for i:= kol downto 2 do {��������� ����������}
  begin
       k:=0;
       for j:=1 to i do    //��������� �� ������� ������ - ������������� ��������
           if ((k=0) or (a[k]> //���������
  kol:=i-1;
  for i:= kol downto 2 do {��������� ����������}
  begin
       k:=0;
       for j:=1 to i do    //��������� �� ������� ������ - ������������� ��������
           if ((k=0) or (M[k]<M[j])) and (M[j]>0) then k:=j;
           if (k>0) and (k<>i) and (M[i]>0) then
           begin
                //�����
                z:=M[i];
                M[i]:=M[k];
                M[k]:=z;
           end;
  end;a[j])) and (a[j]<0) then k:=j;
           if (k>0) and (k<>i) and (a[i]<0) then
           begin
                //�����
                buf:=a[i];
                a[i]:=a[k];
                a[k]:=buf;
           end;
  end;

  writeln('����� ��������������� ������:');
  //�������
  for i:=1 to n do
  begin
  write('a(', i, ')=', a[i], ' ') ;
  end;
readln;

end.
