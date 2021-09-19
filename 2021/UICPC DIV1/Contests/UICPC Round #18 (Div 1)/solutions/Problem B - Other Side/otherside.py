w, s, c, k = map(int, input().split())
if not k:
    print('NO')
elif k > s or k > w+c or k == s == w+c or (k == s and w+c <= 2*k) or (k == w+c and s <= 2*k):
    print('YES')
else:
    print('NO')