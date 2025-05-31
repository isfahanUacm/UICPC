import math
MAX = 100010
answer = []
dp = []
for i in range(2,MAX):
    j = 2
    div = 0
    while j * j <= i :
        if i % j == 0 :
            div += 1
            break
        j += 1
    if div == 0:
        dp.append(i)


for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    ans = 1
    for i in a:
        ans = math.lcm(ans,i)
    
    s = 0
    for p in dp:
        while ans % p == 0:
            ans /= p
            s += 1
    if s % 2 == 0:
        answer.append("Bob")
    else:
        answer.append("Alice")

for i in answer:
    print(i)

    
    