s = len(raw_input().split())
n = int(raw_input())
names = [raw_input() for _ in range(n)]
out = []
at = 0
for i in range(n):
    at = (at+s-1) % len(names)
    out.append(names.pop(at))
print (n+1)/2, ' '.join(out[::2]), n/2, ' '.join(out[1::2])
