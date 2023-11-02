#!/usr/bin/env python

import sys

def main():
  x, y, n = map(int, raw_input().split())

  for z in xrange(1, n+1):
    dx = z % x == 0
    dy = z % y == 0
    if dx and dy:
      print "FizzBuzz"
    elif dx:
      print "Fizz"
    elif dy:
      print "Buzz"
    else:
      print z

if __name__ == "__main__": sys.exit(main())
