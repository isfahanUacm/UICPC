#!/usr/bin/python3
import sys

DEBUG = False

def abend(mess):
  print(mess)
  exit(0)
        
def doCase(theStr): # theStr has at least 2 characters
  thisGP = set() # all chars in case

  for c in theStr:
    thisGP.add(c)
  if DEBUG:
    print(len(thisGP),":",thisGP)
  if len(thisGP) == 1:    # more edge cases
    return 1
    
  lo = 0
  hi = len(theStr) - 1
  allStrs = set()
 
  while lo <= hi:
    gp = set()
    cur = lo
    while (cur < hi) and (theStr[cur] == theStr[cur+1]):  #strip left
      cur +=1
    lo = cur
    while cur <= hi:
      gp.add(theStr[cur])
      if len(gp) == len(thisGP):
        while theStr[lo] in theStr[lo+1:cur+1]:  # more strip left
          lo += 1
        if DEBUG:
          print(lo,cur,hi,theStr[lo:cur+1],gp)
        allStrs.add(theStr[lo:cur+1])
        break 
      cur += 1  
    lo += 1
  if DEBUG:
    print(allStrs)
  if (len(allStrs) == 1) and (theStr in allStrs): # another edge case
    return  0
  return len(allStrs)

thisCase = sys.stdin.readline()
while thisCase:
  thisCase = thisCase.rstrip("\n")  #get rid of end of line
  if len(thisCase) < 1:
    abend("input: no data")
  if DEBUG:
    print(len(thisCase),":",thisCase)
  if len(thisCase) == 1:    # special cases
    ans = 0
  elif len(thisCase) == 2:
    if thisCase[0] == thisCase[1]:
      ans = 1
    else:
      ans = 0
  else:
    ans = doCase(thisCase)
  print(ans)
  thisCase = sys.stdin.readline()
