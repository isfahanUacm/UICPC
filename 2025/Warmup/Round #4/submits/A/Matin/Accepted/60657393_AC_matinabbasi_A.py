from copy import copy
from math import ceil, floor , sqrt
import sys

mapINT = lambda: map(int, sys.stdin.readline().strip().split())
INT = lambda: int(sys.stdin.readline().strip())
LIST = lambda : list(mapINT())

res =[]
def solve():
    
    
    n= INT()
    s =list(input())

    l = []
    for i in range(n):
        x = s.copy()
        # print(i , x)
        x[i] = '0' if x[i]=='1' else '1'
        l.append(x)
    sum =0
    for a in l :
        sum += a.count('1')

    res.append(sum)

    # ln = len()
    pass

t = 1
t = INT()
for i in range(t):solve()  

print(*res)


