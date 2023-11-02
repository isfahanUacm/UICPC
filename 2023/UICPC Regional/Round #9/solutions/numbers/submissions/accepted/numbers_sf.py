#!/usr/bin/env python

import sys
from itertools import groupby

def main():
  for s in testcases():
    if (s == "2") or (s == "4") or (s == "22"):
      print s
    else:
      groups = [(k, sum(1 for _ in g)) for (k, g) in groupby(s)]
      groups.append(('0', 0)) # sentinel

      groups = extendOdd2s(groups)
      groups = extendOdd4s(groups)
      groups = add8sToPowerOfTwo(groups)

      print ''.join(c*k for (c, k) in groups)

def extendOdd2s(groups):
  for (c, k) in groups:
    if (c != '2') or not (k & 1):
      yield (c, k)
    else:
      yield (c, k+1)

def extendOdd4s(groups):
  count = 0
  for (c, k) in groups:
    if (c == '2'):
      count += k // 2
    elif (c == '4'):
      count += k
    else: # note: leverages sentinel
      if count & 1: yield ('4', 1)
      count = 0
    yield (c, k)

def add8sToPowerOfTwo(groups):
  total = 0
  for (c, k) in groups:
    total += int(c) * k
    yield (c, k)

  # at this point, total should be divisible by 8
  n8 = total // 8
  nxtP = 1
  while nxtP < n8: nxtP *= 2

  yield ('8', nxtP - n8)

def testcases():
  t = int(raw_input())
  for _ in xrange(t):
    yield raw_input()

if __name__ == "__main__": sys.exit(main())
