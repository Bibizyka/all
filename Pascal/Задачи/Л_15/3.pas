program V;

uses crt;

var
	s: string;//����������� �����a
	str1,str2: string;//��������� - �������������������
    i: integer;

begin
    //������ ������
    writeln('������� ������:');
    readln(s);
    
    //������������
    //���������, ���������� ������� �������� ������������� � ������������������
    //����� �� 'A' �� 'F' (������ ���������) � �� 'X' �� 'Z' (������ ���������)

    for i:=1 to length(s) do
    begin

         if ((s[i]>'a') and (s[i]<'f'))
         then
             begin
                  str1:=str1+s[i];
             end
             ;
             
         if ((s[i]>'x') and (s[i]<'z'))
         then
             begin
                 str2:=str2+s[i];  //������ 'y'
             end

    end;
    	
   	//�������� ���������
   	writeln('������ ���������:  ', str1);
   	writeln('������ ���������:  ', str2);
end.
