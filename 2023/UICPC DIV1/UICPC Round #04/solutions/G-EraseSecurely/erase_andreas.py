#! /usr/bin/env python

from sys import stdin

n = int(stdin.readline().strip())
a = stdin.readline()
b = stdin.readline()
if n % 2: b = b.replace('0', '2').replace('1', '0').replace('2', '1')

if a == b: print 'Deletion succeeded'
else:      print 'Deletion failed'
