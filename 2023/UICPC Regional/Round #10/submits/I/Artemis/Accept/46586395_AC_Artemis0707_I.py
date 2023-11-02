import math

n = int(input())
t_t = list(map(int, input().split()))
s_t = list(map(int, input().split()))

s = []
t = []
for i in range(len(s_t)):
    if s_t[i]!=-1:
        s.append(s_t[i])
        t.append(t_t[i])

s = [(s[i], t[i]) for i in range(len(s))]
s.sort(key=lambda x: x[0])
#print(s)
ans = 0
sum_t = 0
for i in range(len(s)):
    sum_t += s[i][1]
    ans = max(ans, math.ceil(sum_t/s[i][0]))

print(ans)


