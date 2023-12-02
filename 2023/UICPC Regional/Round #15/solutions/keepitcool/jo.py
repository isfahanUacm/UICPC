n,m,s,d=map(int,raw_input().split())
A=enumerate(map(int,raw_input().split()))
fst=lambda x:x[1]
A=sorted(A, key=fst)
i = 0
F = [0]*s
while i < len(A) and n > 0:
    F[i] = min(n, d - A[i][1])
    n -= F[i]
    i += 1
while i < len(A) and m > 0:
    m -= A[i][1]
    i += 1
ans = 'impossible'
if n == 0 and m <= 0:
    O = [0] * s
    for i in range(len(A)):
        O[A[i][0]] = F[i]
    ans = ' '.join(map(str, O))
print ans
