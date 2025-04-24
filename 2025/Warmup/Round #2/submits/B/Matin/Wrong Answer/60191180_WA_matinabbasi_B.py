from math import gcd
import sys
mapINT = lambda: map(int, sys.stdin.readline().strip().split())
INT = lambda: int(sys.stdin.readline().strip())
LIST = lambda : list(mapINT())


start_x ,start_y =mapINT()
stone_x ,stone_y =mapINT()
end_x ,end_y =mapINT()


if stone_y>0 : stone_y = stone_y+10**8 
else : stone_y = stone_y - 10**8 

if stone_x>0 : stone_x = stone_x+10**8 
else : stone_x = stone_x - 10**8 


next_x = 0-stone_x
next_y = 0-stone_y

print(2)
print(next_x , next_y)
print(0-next_x , end_y)