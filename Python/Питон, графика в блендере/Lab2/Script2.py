import Blender
from Blender import Draw
def event(evt, val):    # 
  if evt == Draw.ESCKEY :	
    Draw.Exit()         # ����� �� ������� ����� ������� �� ESC 
    return

def button_event(evt):  # ��������� ������� �� ������
  if evt == 2:			# 2 � ���������� ����� ������
		print "push"    # �������� ������. ��������� ��������� �� �������
		Draw.Redraw(1)
		return
def gui():              # �������� ������� 
	Draw.PushButton("Push",2,50,10,55,20,"Our push") # �������� ������ �

Draw.Register(gui, event, button_event)  