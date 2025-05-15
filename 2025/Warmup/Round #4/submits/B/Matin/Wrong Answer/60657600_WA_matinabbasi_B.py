from copy import copy
from math import ceil, floor , sqrt
import sys

mapINT = lambda: map(int, sys.stdin.readline().strip().split())
INT = lambda: int(sys.stdin.readline().strip())
LIST = lambda : list(mapINT())

res =[]
def solve():
    

    n , target = mapINT()

    ans =[]
    for i in range(n):
        if i !=target:
            ans.append(i)
    ans.append(target)
    res.append(ans)
    

t = 1
t = INT()
for i in range(t):solve()  

for a in res:
    print(*a)


