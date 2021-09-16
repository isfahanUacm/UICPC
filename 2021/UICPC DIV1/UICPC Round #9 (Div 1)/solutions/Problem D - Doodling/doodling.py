import math
n = int(input())
for i in range(n):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    lc = x * (y // math.gcd(x, y))
    print(lc + 1 - ((lc//x - 1) * (lc//y - 1))//2)