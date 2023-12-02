import math
s = input()
arr = s.split(" ")

n = int(arr[0])
k = int(arr[1])

val = 0

for i in range(n-1):
    val = int(input())

tedMod = 0
ans = 0
ted = 0
mod = 1e9 + 7
for i in range(k):
    ted = (k-i) * pow((k-i-1), n-1, int(mod))
    ted *= math.comb(k, i)
    ted %= int(mod)
    if i % 2 == 0:
        ans += ted
        if ans >= 0:
            ans %= mod
        else:
            tedMod = int(ans / mod) * -1
            ans += (tedMod + 1) * mod
    else:
        ans -= ted

        if ans < 0:
            tedMod = int(ans / mod) * -1
            ans += (tedMod + 1) * mod
        else:
            ans %= mod

print(int(ans%mod))