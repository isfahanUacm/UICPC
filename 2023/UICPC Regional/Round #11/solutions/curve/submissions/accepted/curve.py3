import sys
import math

DEBUG = False

def abend(mess):
  print(mess)
  exit(1)
        
thisCase = sys.stdin.readline()
while thisCase:
  data = thisCase.split()
  if len(data) != 2:
    abend("expecting: radius super-elevation")

  radius = float(data[0])
  super_ev = float(data[1])

  if DEBUG:
    print(radius,super_ev)

  ans = (radius * (super_ev + 0.16) ) / 0.067
  ans = math.sqrt(ans)
  
  print(round(ans))
  thisCase = sys.stdin.readline()
