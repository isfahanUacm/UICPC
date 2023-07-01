#!/usr/bin/env python
# -*- coding: utf-8 -*-
#Solution by lukasP (Lukáš Poláček)
from sys import stdin

n = int(stdin.readline())
a = map(int, stdin.readline().split())
a.sort()
a.reverse()

print max(i + a[i] + 2 for i in range(n))
