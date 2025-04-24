from collections import deque

for _ in range(int(input())):
    n = int( input())    
    l = deque()
    
    for i in range(1,n+1):
        if i%2==1:
            l.append(i)
        else :
            l.appendleft(i)
    print(*l)

    