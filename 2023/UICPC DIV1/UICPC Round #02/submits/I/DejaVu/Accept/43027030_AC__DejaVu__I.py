import math

t = int(input())

for _ in range(t):
    n, c = map(int, input().split())
    print(math.comb(n, c-1))