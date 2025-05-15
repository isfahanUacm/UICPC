from collections import deque
from math import ceil, floor , sqrt
import sys
mapINT = lambda: map(int, sys.stdin.readline().strip().split())
INT = lambda: int(sys.stdin.readline().strip())
LIST = lambda : list(mapINT())

res =[]
def solve():
    

    n = deque(map(int , list(input())))
    
    sm = 0
    # print(n[len(n)-1])
    while(n[len(n)-1]==0):
        n.pop()
        sm +=1
    # print(sm, "-------------")
    for a in n:
        if a!=0:
            sm +=1
    # print(sm, "-------------")

    sm -=1
    res.append(sm)

t = 1
t = INT()
for i in range(t):solve()  

print(*res)


