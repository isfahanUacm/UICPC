"""
Solution for Bridge Automation.

This program implements exactly the algorithm from
the solution presentation slide to check that it works.
"""

#
# This program is correct, and about as fast as you can expect
# from a Python program. And yet it may be too slow for this problem.
# That's ok; Python is allowed in this contest, but it is not considered
# a fully supported contest language.
#

# @EXPECTED_RESULTS@: CORRECT, TIMELIMIT

import sys


def solve(boats):

    n = len(boats)
    table = (n + 1) * [ None ]

    table[0] = 0
    for p in range(1, n+1):
        table[p] = min([ ( table[p-k] +
                           max(boats[p-1] - boats[p-k] - 1800 + 20, 20 * k) +
                           120 )
                         for k in range(1, p+1) ])

    return table[n]


def main():

    s = sys.stdin.readline()
    n = int(s.strip())

    boats = [ ]
    for i in range(n):
        s = sys.stdin.readline()
        boats.append(int(s.strip()))

    ans = solve(boats)
    print ans

main()

