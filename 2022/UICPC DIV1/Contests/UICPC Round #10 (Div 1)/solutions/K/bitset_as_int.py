n = int(input())
P = list(map(int, input().split()))
P = [0, 0] + P

V = [0] * (n+1)
for v in range(n, 0, -1):
    V[v] += 1
    V[P[v]] += V[v]

centroid = 1
for v in range(2, n+1):
    if 2*V[v] >= n:
        centroid = v
bef = 0
v = centroid
while v:
    bef, V[v] = V[v], n - bef
    v = P[v]

cnt = [0] * (n+1)
if P[centroid]:
    cnt[V[P[centroid]]] += 1

for v in range(2, n+1):
    if P[v] == centroid:
        cnt[V[v]] += 1

S = []

for x in range(1, n+1):
    while cnt[x] >= 3:
        cnt[2*x] += 1
        cnt[x] -= 2
    for i in range(cnt[x]):
        S.append(x)

n2 = n // 2
M = [False] * (n2 + 1)

_M = 1
_sum = 0
for x in S:
    _sum += x
    _M |= _M << x

M = format(_M, 'b')

res = 0
for i in range(n//2, -1, -1):
    if M[i] == '1':
        res += i * (n-1-i)
        break

for v in range(1, n+1):
    res += V[v];
 
print(res)
