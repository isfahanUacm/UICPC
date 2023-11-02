import sys

a1 = []
mp = {}
while True:
    s = sys.stdin.readline()
    if s == "\n" or s == '':
        break

    first, last, email = s.split()
    f = first.lower()
    l = last.lower()
    e = email.lower()
    a1.append((e, f + ' ' + l))
    mp[e + ' ' + f  + ' ' + l] = email + ' ' + last  + ' ' + first


a2 = []
mp2 = {}
while True:
    s = sys.stdin.readline()
    if s == "\n" or s == '':
        break
    
    first, last, email = s.split()

    f = first.lower()
    l = last.lower()
    e = email.lower()
    a2.append((e, f + ' ' + l))
    mp2[e + ' ' + f  + ' ' + l] = email + ' ' + last  + ' ' + first
    
all = False

aim1 = []
for value in a1:
    fg = True
    name = value[1]
    em = value[0]
    
    for val in a2:
        if val[0] == em or val[1] == name:
            fg = False
            break
        
    if fg:
        all = True
        aim1.append(value)

aim2 = []  
for value in a2:
    fg = True
    name = value[1]
    em = value[0]
    
    for val in a1:
        if val[0] == em or val[1] == name:
            fg = False
            break
        
    if fg:
        all = True
        aim2.append(value)

if not all:
    print("No mismatches.")
else:
    aim1 = sorted(aim1)
    aim2 = sorted(aim2)
    
    for val in aim1:
        print(f"I {mp[val[0] + ' ' + val[1]]}")
        
    for val in aim2:
        print(f"O {mp2[val[0] + ' ' + val[1]]}")
