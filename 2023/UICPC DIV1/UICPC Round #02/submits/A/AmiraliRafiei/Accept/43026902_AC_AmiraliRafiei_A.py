n, t = map(int, input().split())
a = [int(x) for x in input().split()]
result = 0

for i in range (n):
    if t >= a[i]:
        t -= a[i]
        result = i+1
    else:
        break

print(result)
