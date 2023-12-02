n = int(raw_input())
T = map(int, raw_input().split())
(t, d) = min([(max(T[i], T[i+2]), i+1) for i in range(n-2)])
print d, t
