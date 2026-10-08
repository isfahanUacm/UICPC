n =int(input())
s = int(input())
dire = str(input())

if dire == "L":
    r3 = n-s
    if s%2==1:
       r2 = s//2 + 1
       r1 = r2
    else:
        r2 = s//2
        r1 = r2
else:
    r1 = s-1
    if (n-s+1)%2==1:
       r2 = (n-s+1)//2 + 1
       r3 = r2
    else:
        r2 = (n-s+1)//2
        r3 = r2
if r1 == 0:
    r1 = 1
if r2 == 0:
    r2 = 1
if r3 == 0:
    r3 = 1
print(r1, r2, r3, sep=' ')

