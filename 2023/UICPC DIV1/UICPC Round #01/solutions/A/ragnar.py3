#!/usr/bin/env python3
l = lambda: [int(x) for x in input().split()] 
l()
print('possible' if max(l()) == max(l()) else 'impossible')
