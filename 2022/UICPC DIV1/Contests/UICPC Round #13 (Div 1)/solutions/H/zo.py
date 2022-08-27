"""
Solves Zebras and Ocelots
Rob Hochberg
"""

from sys import stdin
S = int(stdin.readline())

numBells = 0
for i in range(S):
    animal = stdin.readline().strip()
    numBells = (numBells << 1) | (1 if animal == 'O' else 0)

print numBells
