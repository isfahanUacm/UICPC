n = int(input())
x = [0] * (n*n)
y = [0] * (n*n)
for i in range(n):
    q = list(map(int, input().split()))
    for j in range(n):
        qq = q[j] - 1
        x[qq] = i
        y[qq] = j

res = (n*(n-1)) // 2
res = 2 * res * res

row = [0]*n
col = [0]*n
for q in range(n*n):
    res -= row[x[q]]*col[y[q]]
    row[x[q]] += 1
    col[y[q]] += 1

print(res)
