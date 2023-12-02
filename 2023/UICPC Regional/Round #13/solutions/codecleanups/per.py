import sys

c = [0]*366
for d in map(int, sys.stdin.read().split()[1:]):
    c[d] += 1

ans = delta = dirt = 0
for d in range(1, 366):
    delta += c[d]
    dirt += delta
    if dirt >= 20:
        ans += 1
        dirt = delta = 0

if dirt:
    ans += 1

print ans
