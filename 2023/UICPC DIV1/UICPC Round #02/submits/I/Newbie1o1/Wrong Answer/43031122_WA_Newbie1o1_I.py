import math

def num_locks(n, m):
    return math.comb(n, m) - 1

t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    print(num_locks(n, m))
