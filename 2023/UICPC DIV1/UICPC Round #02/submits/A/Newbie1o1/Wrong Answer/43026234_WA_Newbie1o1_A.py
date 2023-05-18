n, T = map(int, input().split())
numbers = list(map(int, input().split()))

sum = 0
g = 0
for h in range(n):
    sum += numbers[h]
    if sum > T:
        print(g)
        break
    g += 1
