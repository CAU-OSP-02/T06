import maya.cmds as cmds
cmds.polyPlane(sx=9,sy=9)
#list = [1, 79, 10, 12, 14, 16, 28, 30, 32, 34, 46, 48, 50, 52, 64, 66, 68, 70, 25, 43, 61, 65, 67, 69, 11, 13, 23, 37, 31, 41, 47, 57, 51]
cmds.delete('pPlane1.f[1]'
,'pPlane1.f[79]','pPlane1.f[10]','pPlane1.f[12]','pPlane1.f[14]',
'pPlane1.f[16]','pPlane1.f[28]','pPlane1.f[30]','pPlane1.f[32]'
,'pPlane1.f[34]','pPlane1.f[46]','pPlane1.f[48]',
'pPlane1.f[50]','pPlane1.f[52]','pPlane1.f[64]',
'pPlane1.f[66]','pPlane1.f[68]','pPlane1.f[70]',
'pPlane1.f[25]','pPlane1.f[43]','pPlane1.f[61]'
,'pPlane1.f[65]','pPlane1.f[67]','pPlane1.f[69]','pPlane1.f[11]'
,'pPlane1.f[13]','pPlane1.f[23]','pPlane1.f[37]',
'pPlane1.f[31]','pPlane1.f[41]','pPlane1.f[47]','pPlane1.f[57]'
,'pPlane1.f[51]')
cmds.scale(25,1,25,'pPlane1')
cmds.polyExtrudeFacet('pPlane1',ltz=20)
        
        
