#!/usr/bin/env/python

from sys import stdin
from re import match

rep="""***   * *** *** * * *** *** *** *** ***
* *   *   *   * * * *   *     * * * * *
* *   * *** *** *** *** ***   * *** ***
* *   * *     *   *   * * *   * * *   *
***   * *** ***   * *** ***   * *** ***"""

digits = zip(*[zip(r[::4],r[1::4],r[2::4]) for r in rep.split('\n')])

case = stdin.readlines()
data = zip(*[zip(r[::4],r[1::4],r[2::4]) for r in case])
mod2=0
mod3=0
ok=False
try:
    for num in data :
        i=digits.index(num)
        mod3+=i;
        mod3%=3;
        mod2=i%2;
    if mod3 == 0 and mod2 == 0:
        ok=True
except:
    pass

if ok:
    print "BEER!!"
else:
    print "BOOM!!"
