#!/usr/bin/env python

import sys

def main():
  ev, cur = 0, 0
  for (p, _) in sorted(readPasses()):
    cur += p
    ev += cur

  print "{0:.4f}".format(ev)

def readPasses():
  n = int(raw_input())
  for _ in xrange(n):
    pw, prob = raw_input().split()
    yield (float(prob), pw)

if __name__ == "__main__": sys.exit(main())
