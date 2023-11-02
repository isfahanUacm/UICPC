#!/usr/bin/env python

import sys

def main():
  for (n, v1, v2, w) in testcases():
    r = n - v1 - v2
    pascal = [1]
    for i in xrange(1, r+1):
      pascal.append(pascal[-1] * (r+1-i) // i)

    lb = max(0, 1 + (v2 - v1 + r) // 2)
    win = sum(pascal[i] for i in xrange(lb, r+1))
    tot = sum(pascal)

    if win == 0:
      print "RECOUNT!"
    elif 100*win > w*tot:
      print "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!"
    else:
      print "PATIENCE, EVERYONE!"

def testcases():
  t = int(raw_input())
  for _ in xrange(t):
    n, v1, v2, w = map(int, raw_input().split())
    yield (n, v1, v2, w)

if __name__ == "__main__": sys.exit(main())
