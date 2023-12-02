import sys

n, s = map(int, sys.stdin.readline().strip().split())
arr = []
for i in range(n):
    name, bet = sys.stdin.readline().strip().split()
    bet = int(bet)
    arr.append((name, bet))
arr = sorted(arr, key=lambda x: -x[1])

left = s
found = []
for (name, bet) in arr:
    if bet <= left:
        left -= bet
        found.append(name)

if left != 0:
    sys.stdout.write('0\n')
else:
    sys.stdout.write('%d\n' % len(found))
    for name in found:
        sys.stdout.write('%s\n' % name)

