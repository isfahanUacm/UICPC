#!/bin/python3

[n,k] = [int(x) for x in input().split()]
k -= 1

factorial = [1 for _ in range(n+1)]
for i in range(1,n+1):
    factorial[i] = factorial[i-1] * i

ans = []
perm = [0]
used = [False for _ in range(n)]

for i in range(n-1):
    possible = []
    for j in range(1,n):
        if not used[j]:
            possible.append( [(j-perm[i]) % n , j] )
    possible.sort()

    for x in possible:
        if factorial[n-i-2] <= k:
            k -= factorial[n-i-2]
            continue
        ans.append(x[0])
        perm.append(x[1])
        used[x[1]] = True
        break

print(*ans, sep=' ')
