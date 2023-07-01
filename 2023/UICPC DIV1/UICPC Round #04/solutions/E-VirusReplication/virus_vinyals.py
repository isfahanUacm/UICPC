#!/usr/bin/env python

from sys import stdin

s1=stdin.readline()
s2=stdin.readline()
l1=len(s1)
l2=len(s2)
l=min(l1,l2)
lastok=-1
for i in xrange(l):
    lastok=i
    if s1[i]!=s2[i] :
        break
l-=lastok
firstfail=l
for i in xrange(l):
    if s1[l1-i-1]!=s2[l2-i-1] :
        firstfail=i
        break
print l2-firstfail-lastok
