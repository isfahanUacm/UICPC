#!/usr/bin/env python

import sys

def main():
  x1, x2 = map(int, raw_input().split())
  t1 = map(int, raw_input().split()[1:])
  t2 = map(int, raw_input().split()[1:])

  coll = collisionTime(x1, t1, x2, t2)
  if coll is not None:
    print "bumper tap at time {0}".format(coll)
  else:
    print "safe and sound"

def collisionTime(x1, t1, x2, t2):
  if (x2 < x1): return collisionTime(x2, t2, x1, t1)

  events = [(float('inf'), 0)] # sentinel
  events.extend((t, -(-1)**i) for (i, t) in enumerate(t1))
  events.extend((t, (-1)**i) for (i, t) in enumerate(t2))
  events.sort()

  CLEARANCE = 5
  delta = x2 - x1
  curT, curV = 0, 0

  for (t, dv) in events:
    dt = t - curT
    if (curV == -1) and (delta - dt < CLEARANCE):
      return curT + delta - CLEARANCE + 1

    delta += curV * dt
    curV += dv
    curT = t

  return None

if __name__ == "__main__": sys.exit(main())
