#!/usr/bin/env python

import sys
from itertools import groupby

def main():
  for s in testcases():
    n, nxts = preprocess(s)
    calc = makeCalc(n, nxts)

    print (len(s) + 2 * calc(0, n))

def testcases():
  t = int(raw_input())
  for _ in xrange(t):
    yield raw_input()

def preprocess(s):
  ss = ''.join(c for (c, _) in groupby(s))
  n = len(ss)

  last = dict()
  nxt = [None] * n

  for (i, c) in enumerate(ss):
    if c in last:
      nxt[last[c]] = i
    last[c] = i

  def nxts(a, b):
    a = nxt[a]
    while (a is not None) and (a < b):
      yield a
      a = nxt[a]

  return (n, nxts)

def makeCalc(n, nxts):
  memo = [[0]*(n+1) for _ in xrange(n)]
  def calc(a, b):
    if a >= b: return 0
    if b == a+1: return 1
    if not memo[a][b]:
      # does not become top again before we finish
      best = 1 + calc(a+1, b)

      # becomes top again at index i
      # note: calc(i, b) includes +1 for this push
      for i in nxts(a, b):
        best = min(best, calc(a+1, i) + calc(i, b))

      memo[a][b] = best
    return memo[a][b]

  return calc

if __name__ == "__main__": sys.exit(main())
