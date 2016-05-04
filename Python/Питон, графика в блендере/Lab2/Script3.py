import os
import Blender
from Blender import Draw
os.system("cls")
allPoints=[]			# ����� ���������� ��� ��������� ������
def event(evt, val):    #��������� ������� ������
	if evt == Draw.ESCKEY :	
		Draw.Exit()         # exit when user presses ESC		
def button_event(evt):  # �������� ������� ��� ������������ ������� � �����
	global allPoints
  	if evt == 1:			# 1 � ������������� ������ ������
		x=Draw.Create(0)
		y=Draw.Create(0)		# �������� ������ � ���������� �������
		block=[]			# ������ ��� ������������ ������� 
		block.append(("X= ",x,0,400)) #���� � ������������ ������ � ���� ������
		block.append(("Y= ",y,0,600))
		retVal=Draw.PupBlock("Line coords",block) # �������� �������
		allPoints.append(x.val)
		allPoints.append(y.val)   # ���������� ������
		print "data", allPoints
		Draw.Redraw(1)
		return

def gui():              # 
	Draw.PushButton("Add point",1,1,10,65,20,"Add point to polygon")
Draw.Register(gui, event, button_event)  # registering the 3 callbacks



# homework 2_2
import math
import os
from math import cos,sqrt

os.system('cls')

def cosinusTheoreme(b,c,A):
	pi= math.pi
	c=sqrt(b**2+c**2-2*b*c*cos(pi*(A/180.0)))
	return c


print '-> Result for b=2, c=2, A=45\' c= ', cosinusTheoreme(2,2,45)
print '-> Result for b=2, c=2, A=90\' c= ', cosinusTheoreme(2,2,90)
print '-> Result for b=2, c=2, A=175\' c= ', cosinusTheoreme(2,2,175)
