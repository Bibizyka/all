program V3;
uses crt;
const N = 2;
type
	Student = record
		familia: string; //�������
		imya: string; //���
		otchestvo: string;//��������
		telefon: integer;  //����� ��������
	end;
var
   //������ ���������
	a: array [1..N] of Student;
	i: integer;

    //������ ���������: �+�+�+����.
begin
	for i := 1 to N do
	begin
		writeln('�������  ������� �������� �', i);
		readln(a[i].familia);
		writeln('�������  ��� ��������', i);
		readln(a[i].imya);
		writeln('�������  �������� ��������', i);
		readln(a[i].otchestvo);
		writeln('�������  ����� �������� ��������(0 - ���� ��� ������)', i);
		readln(a[i].telefon);
	end;
	
	//������� ��� ��������� ��� ������ ��������
	for i := 1 to N do
	begin
	     if a[i].telefon=0
	     then Writeln(i,'. ',a[i].familia,' ',a[i].imya,' ',a[i].telefon);
	end;
	
end.
