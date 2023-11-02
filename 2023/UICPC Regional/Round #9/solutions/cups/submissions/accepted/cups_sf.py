#!/usr/bin/env python

import sys

def main():
  n = int(raw_input())
  cups = []
  for _ in xrange(n):
    a, b = raw_input().split()
    if a.isdigit():
      cups.append((int(a), b))
    else:
      cups.append((2*int(b), a))

  cups.sort()
  print '\n'.join(c[1] for c in cups)

if __name__ == "__main__": sys.exit(main())
