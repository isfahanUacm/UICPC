#!/usr/bin/python3

def solve(str):
    if len(str) == 1 or str == "22": return str

    # lazy thinking, can probably combine the two loops into 1
    i = 0
    mod4 = 0
    while i < len(str) or mod4:
        if (i == len(str) or str[i] != '2') and mod4:
            str = str[:i] + '2' + str[i:]
            mod4 = 0
        else:
            mod4 = (mod4 + int(str[i]))%4;
        i = i+1

    i = 0
    mod8 = 0
    while i < len(str) or mod8:
        if (i == len(str) or str[i] == '8') and mod8:
            str = str[:i] + '4' + str[i:]
            mod8 = 0
        else:
            mod8 = (mod8 + int(str[i]))%8
        i = i+1

    tot = 0
    for c in str:
        tot += int(c)

    while tot&(tot-1):
        str += "8"
        tot += 8

    return str

t = int(input())
for i in range(t):
    str = input()
    print(solve(str))
