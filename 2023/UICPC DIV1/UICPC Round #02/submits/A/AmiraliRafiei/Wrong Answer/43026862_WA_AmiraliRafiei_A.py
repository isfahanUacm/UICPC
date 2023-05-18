n, t = map(int, input().split())
a = [int(x) for x in input().split()]

for i in range (n):
    if t >= a[i]:
        t -= a[i]
    else:
        print(i)
        break