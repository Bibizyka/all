import Blender
from Blender import Draw,BGL
mystr=""
def event(evt, val):    # ��� ������� ������������ ���������� �� ���������� � ����
	global mystr
	if evt == Draw.ESCKEY:
    		Draw.Exit()                 # ����� �� �������
    		return
  	if val==0 and evt ==Draw.LEFTMOUSE:
		coor=Blender.Window.GetMouseCoords()
		print coor
		mystr =str(coor[0])+"  "+str(coor[1])
		Draw.Redraw(1)


		

def gui():              # function drawing in screen
 	BGL.glRasterPos2i(10, 230) # ��������� �������
  	Draw.Text("coods"+" "+mystr)
  	
Draw.Register(gui, event, None)