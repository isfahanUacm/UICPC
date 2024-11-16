import sys
import math
from bisect import bisect_right
from itertools import product

inf = int(1e18)

def generate_p():
    p = {1, 10}
    
    for i, j, a, b in product(range(55), range(55), range(19), range(19)):
        if 0 < i / 3 + j / 2 + a + b <= 20:
            digit = []

            t = i
            while t >= 3:
                digit.append(8)
                t -= 3
            if t >= 2:
                digit.append(4)
                t -= 2
            t1 = t

            t = j
            while t >= 2:
                digit.append(9)
                t -= 2
            t2 = t

            digit += [5] * a
            digit += [7] * b

            if t1 == 1 and t2 == 1:
                digit += [6]
            elif t1 == 1:
                digit += [2]
            elif t2 == 1:
                digit += [3]

            digit.sort()
            pq = int(''.join(map(str, digit)))
            if pq < inf:
                p.add(pq)
                
    return sorted(p)

def solve():
    p = generate_p()
    t = int(input().strip())

    for _ in range(t):
        n = int(input().strip())
        idx = bisect_right(p, n) - 1
        print(idx + 1)

if __name__ == "__main__":
    solve()
