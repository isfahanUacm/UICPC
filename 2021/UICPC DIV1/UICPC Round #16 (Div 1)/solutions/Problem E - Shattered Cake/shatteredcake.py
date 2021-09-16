w = int(input())
n = int(input())
s = 0
for i in range(n):
    a, b = map(int, input().split())
    s += a * b
print(s//w)