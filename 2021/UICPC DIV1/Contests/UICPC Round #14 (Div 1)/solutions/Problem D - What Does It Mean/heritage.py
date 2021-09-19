n, s = map(str, input().split())
mod = 1000000007
n = int(n)
di = list()
for i in range(n):
    w, a = map(str, input().split())
    di.append((w, int(a)))
calc = [0 for i in range(len(s)+1)]
calc[0] = 1
for i in range(len(s)):
    for w in di:
        if s[i:i+len(w[0])] == w[0]:
            calc[i+len(w[0])] += calc[i] * w[1]
print(calc[len(s)] % mod)
