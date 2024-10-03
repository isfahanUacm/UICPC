#!/usr/bin/env python3
N = int(input())
L = input()
print(sum(1 if "1" in L[max(0,i-2):i+1] else 0 for i in range(N)))
