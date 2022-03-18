lis = ['C','C#','D','D#','E','F','F#','G','G#','A','A#','B']
n = int(input())

f = input().split()
s = input().split()
d = lis.index(s[0]) - lis.index(f[0])
transpo = True
for j in range(n):
    if lis.index(s[j]) - lis.index(f[j]) != d:
        transpo = False
        break
if transpo:
    print('Transposition')
    exit(0)
retr = True
for j in range(n):
    if f[j] != s[n-1-j]:
        retr = False
        break
if retr:
    print('Retrograde')
    exit(0)
inv = True
if f[0] != s[0]:
    print('Nonsense')
    exit(0)
idx = lis.index(f[0])
for j in range(1, n):
    ii = lis.index(f[j])
    dd = idx - ii
    if lis[(ii+2*dd+12) % 12] != s[j]:
        inv = False
        break
if inv:
    print('Inversion')
else:
    print('Nonsense')
