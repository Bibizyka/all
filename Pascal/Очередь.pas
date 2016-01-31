
//������ �������
Type
  EXO = ^O;
  O = record
       Data : integer;//����������
       Next : EXO;//��������� �� ��������� �������
  end;

//������ ���������� ��� ������ � ��������
Var
BeginO, EndO : EXO;//������ � �����


//��������� �������� � �������
Procedure writeO(Var BeginO, EndO : EXO; c : integer);
Var
  u : EXO;
Begin
  new(u);
  u^.Data := c;
  u^.Next := Nil;
  if BeginO = Nil {���������, ����� �� �������}
    then
      BeginO := u {������ ��������� ������ ������� �� ������ ��������� �������}
    else
      EndO^.Next := u; {������ ��������� ������� � ����� �������}
  EndO := u; {��������� ��������� ����� ������� �� ��������� �������}
End;

//��������� ���������� �������� �� �������
//��� �� ��������� - �� ����� �� �������?
Procedure readO(Var BeginO : EXO; Var c : integer);
Var
  u : EXO;
Function FreeO(x1 : EXO): boolean;
Begin
  FreeO := (x1 = Nil);
End;
Begin
  if FreeO(BeginO)
    then
      writeln('������� �����')
    else
      begin
        c := BeginO^.Data; {��������� ������� �������� � ���������� �}
        u := BeginO; {������ ������������� ��������� �� ������ ������� �������}
        BeginO := BeginO^.Next;{��������� ������ ��������� �� ��������� �������}
        dispose(u); {����������� ������, ������� ��� �������� ������ ���������}
      end;
End;
