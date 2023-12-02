import sys
import math

size, n = map(lambda x:int(x), sys.stdin.readline().split(' '))
cheapest = 1e9
candidates = []
for i in range(n):
    line = sys.stdin.readline().split(',')
    (price,capacity,cutting_time,recharge_time) = map(lambda x:int(x), line[1:])

    total_cut = 10080 * cutting_time * capacity
    if total_cut >= (cutting_time + recharge_time) * size:
        if price < cheapest:
            cheapest = price
            candidates = [line[0]]
        elif price == cheapest:
            candidates.append(line[0])

for c in candidates:
    print(c)
if len(candidates) == 0:
    print('no such mower')
