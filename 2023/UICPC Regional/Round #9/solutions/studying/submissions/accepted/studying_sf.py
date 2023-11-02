#!/usr/bin/env python

import sys

def main():
  n, totT = map(int, raw_input().split())

  funcs = [tuple(map(float, raw_input().split())) for _ in xrange(n)]
  slope = findSlope(funcs, totT)
  grade = sum(fValAtSlope(f, slope) for f in funcs) / n

  print "{0:.6f}".format(grade)

def findSlope(funcs, totT):
  def calcT(slope):
    return sum(slope2Time(a, b, slope) for (a, b, _) in funcs)

  lo = 0
  hi = max(b for (_, b, _) in funcs)
  while hi-lo > 1E-9:
    mid = (lo + hi) / 2
    if calcT(mid) > totT:
      lo = mid
    else:
      hi = mid

  return hi

def slope2Time(a, b, slope):
  return max(0, (slope - b) / (2 * a))

def fValAtSlope((a, b, c), slope):
  t = slope2Time(a, b, slope)
  return a*t*t + b*t + c

if __name__ == "__main__": sys.exit(main())
