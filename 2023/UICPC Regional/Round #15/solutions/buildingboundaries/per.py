def solve():
    L = map(int, raw_input().split())
    X = zip([0,1,2]*2, L[::2]+L[1::2], L[1::2]+L[::2])
    print min(min(max(a1+a2,a3)*(b1+b3), (a1+a2+a3)*max(b1,b2,b3), max(a1+a2,a1+a3)*max(b1,b2+b3))
              for (i,a1,b1) in X for (j,a2,b2) in X for (k,a3,b3) in X
              if i != j and i+j+k == 3 and b2 <= b1)

for _ in range(int(raw_input())): solve()
