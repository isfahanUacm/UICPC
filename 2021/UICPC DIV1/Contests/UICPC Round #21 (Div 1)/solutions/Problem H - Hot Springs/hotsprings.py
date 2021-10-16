n = int(input())
li = sorted(list(map(int, input().split())))
i = 0
j = n-1
res = []
while i < j:
    res.append(li[i])
    res.append(li[j])
    i += 1
    j -= 1
if i == j:
    res.append(li[i])
print(' '.join([str(a) for a in reversed(res)]))
