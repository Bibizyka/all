program V3;
uses crt;
const N = 2;
type
	Car = record
		brand: string; //����� ������
		power: integer; //��������� ����
	end;
var
   //������ �����
	a: array [1..N] of Car;
	sum, i: integer;

    //������ ������: �������� ������ � ��������� ����
begin
	for i := 1 to N do
	begin
		writeln('�������  ', i, ' ����� ������');
		readln(a[i].brand);
		writeln('������� ���������� ��������� ��� ', i, '  ������');
		readln(a[i].power);
	end;
	sum := 0;
	
	//���������(�� ������� ������)
	for i := 1 to N do
	begin
		sum := sum + a[i].power;
	end;
	//������� ������� �����
	Writeln(sum / N);
end.
