inputline = input().split(" ")
FirstinputLine = input().split(" ")
SecondinputLine = input().split(" ")


east = []
north = []
for i in FirstinputLine: 
    east.append(int(i))
for i in SecondinputLine:
    north.append(int(i))
maxEast = east[0]
for i in east:
    if i > maxEast :
        maxEast = i
maxNorth = north[0]
for i in north:
    if maxNorth < i :
        maxNorth = i
if maxEast == maxNorth :
    print("possible")
else :
    print("impossible")