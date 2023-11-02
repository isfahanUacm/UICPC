centerx, centery = map(float, input().split())
r = float(input())


x1,y1 = centerx - r, centery - r
x3,y3 = centerx - r, centery + r
x2,y2 = centerx + r, centery + r
x4,y4 = centerx + r, centery - r

print(x1,y1)
print(x3,y3)
print(x2,y2)
print(x4,y4)
