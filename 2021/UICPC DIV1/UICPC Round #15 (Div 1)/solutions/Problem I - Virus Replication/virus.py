a = input()
b = input()
f1 = len(a)
le = min(len(a), len(b))
f2 = len(b)
j = 0
for i in range(le):
    if a[i] != b[i]:
        break
    j += 1
k = 0
for i in range(le-j):
    if a[len(a)-1-i] != b[len(b)-1-i]:
        break
    k += 1
print(f2-k-j)