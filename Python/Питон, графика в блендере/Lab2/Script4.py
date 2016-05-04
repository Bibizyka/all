import Blender
from Blender import Draw,BGL
import os
os.system("cls")
mystring = ""
def event(evt, val):    # ��� ������� ������������ ���������� �� ���������� � ����
	if evt == Draw.ESCKEY:
    		Draw.Exit()                 # ����� �� �������
    		return
 	global mystring#, mymsg
  	if Draw.AKEY <= evt <= Draw.ZKEY:
		if val==0:	#����� ����� �� ���������� ��� ����
			mystring += chr(evt) 
	# ��� ����������� ��� ������� �� ���������� �������. chr(evt) ����������� ������ ������� � 	��������������� ������
			Draw.Redraw(1)

def gui():              # function drawing in screen
 	BGL.glRasterPos2i(10, 230) # ��������� �������
  	Draw.Text("Type letters from a to z, ESC to leave.")
  	BGL.glRasterPos2i(20, 200)
  	Draw.Text(mystring)
Draw.Register(gui, event, None)  # ����������� ������� � ������ ��������� �����