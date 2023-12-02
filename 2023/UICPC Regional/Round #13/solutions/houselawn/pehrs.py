from sys import stdin
from collections import defaultdict

[lawn, n] = map(int, stdin.readline().split())
min_price = 100001
accepted = defaultdict(list)

for i in range(0, n):
    [name, data] = stdin.readline().split(',', 1)
    [price, c, t, r] = map(float, data.split(','))
    #Cut per cycle
    cut = c*t
    cycle_length = t+r
    cycles_per_week = 10080/cycle_length
    cut_per_week = cycles_per_week * cut
    if cut_per_week >= lawn:
        #Enough capacity
        accepted[price] += [name]
        min_price = min(min_price, price)

if min_price != 100001:
    for name in accepted[min_price]:
        print name
else:
    print "No such mower"
