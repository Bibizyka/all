program V3;
uses crt;
const N = 2;
type
	Student = record
		familia: string; //�������
		imya: string; //���
		otchestvo: string;//��������
		rost: integer;
	end;
var
   //������ ���������
	a: array [1..N] of Student;
	sum, i: integer;

    //������ ���������: �+�+�+����.
begin
	for i := 1 to N do
	begin
		writeln('�������  ������� ��������', i);
		readln(a[i].familia);
		writeln('�������  ��� ��������', i);
		readln(a[i].imya);
		writeln('�������  �������� ��������', i);
		readln(a[i].otchestvo);
		writeln('�������  ���� ��������', i);
		readln(a[i].rost);
	end;
	sum := 0;
	
	//���������(�� ������� ������)
	for i := 1 to N do
	begin
		sum := sum + a[i].rost;
	end;
	
	//������� ������� �����(������ ���������)
	Writeln('������� ���� ��������� = ',sum / N);
end.
