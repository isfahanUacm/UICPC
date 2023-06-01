#!/usr/bin/python3
n, p, s = map(int, input().split())

for _ in range(s): print ("KEEP" if p in list(map(int, input().split()))[1:] else "REMOVE")
