import Blender
from Blender.Mathutils import *
# ���� ��� ����� �� ���������
pt0=Vector([100,100,0])
pt1=Vector(100,200,0)  
pt2=Vector(10,300,0)
# ������� ������������
dpt01=pt1-pt0
dpt02=pt2-pt0
# ��������� ������������
crss=CrossVecs(dpt01,dpt02)# ��� ���������� ������ �������
# crss=dpt02.cross(dpt01)  ������� ��� ����� ������
# ����� �������
ln=crss.length
# � ������ ������� ������������ � ������� ���������� �������
sq=TriangleArea(pt0,pt1,pt2)
print 'ln',ln/2
print 'sq',sq