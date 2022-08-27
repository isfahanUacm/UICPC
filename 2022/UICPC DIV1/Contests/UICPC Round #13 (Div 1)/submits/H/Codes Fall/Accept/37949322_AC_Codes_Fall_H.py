n = int(input())
l = []
for _ in range(n):
    l.append(input())

l = reversed(l)
plus = 0

for i, n in enumerate(l):
    if n == "O":
        plus += 2 ** i

print(plus)
