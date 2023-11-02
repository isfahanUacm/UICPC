#!/usr/bin/env python

import sys

def main():
  n, m, pMatrix = readInput()

  ready = [0]*n
  for j in xrange(m):
    ready[0] += pMatrix[0][j]
    for i in xrange(1, n):
      ready[i] = max(ready[i], ready[i-1]) + pMatrix[i][j]

  print ' '.join(str(t) for t in ready)

def readInput():
  n, m = map(int, raw_input().split())

  return (n, m, [[int(v, 10) for v in raw_input().split()] for _ in xrange(n)])

if __name__ == "__main__": sys.exit(main())
