import sys

n,s = map(lambda x:int(x), sys.stdin.readline().split(' '))
bets = []
for i in range(n):
    name,bet = sys.stdin.readline().split(' ')
    bets.append((name, int(bet)))
bets.sort(lambda x,y:1 if y[1]-x[1]>0 else -1)

winners = []
for b in bets:
    if b[1] <= s:
        s -= b[1]
        winners.append(b[0])
if s == 0:
    print(len(winners))
    for w in winners:
        print w
else:
    print(0)
