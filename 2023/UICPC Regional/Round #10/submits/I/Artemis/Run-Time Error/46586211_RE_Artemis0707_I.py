import math

n = int(input())

t = list(map(int, input().split()))
s = list(map(int, input().split()))
pops = []
for i in range(n):
    if s[i] == -1:
        pops.append(i)

for i in pops:
    t.pop(i)
    s.pop(i)

s = [(s[i], t[i]) for i in range(len(s))]
s.sort(key=lambda x: x[0])

ans = 0
sum_t = 0
for i in range(len(s)):
    sum_t += s[i][1]
    ans = max(ans, math.ceil(sum_t/s[i][0]))

print(ans)


