from math import floor
def ok(n):
    a1 = (1 + (8*n+1)**0.5) / 2 
    #print(a1)
    if floor(a1) == a1 and a1 > 0:
        return int(a1)
    
    return -1

a,b,c,d = map(int,input().split())

a1 = 0
if a != 0:
    a1 = ok(a)

if a1 == -1:
    print("impossible")
    exit()

d1 = 0 
if d != 0:
    d1 = ok(d)

if d1 == -1:
    print("impossible")
    exit()
    
if d == 0 and b == 0 and c == 0 and a == 0:
    print("0")
    exit()


if a != 0 and b == 0 and c == 0 and d == 0:
    print(a1 * '0')
    exit()

if d != 0 and b == 0 and c == 0 and a == 0:
    print(d1 * '1')
    exit()
    
if d == 0 and b == 1 and c == 0 and a == 0:
    print('01')
    exit()

if d == 0 and b == 0 and c == 1 and a == 0:
    print('10')
    exit()
    
if a == 0 and d > 0:
    if b + c != d1:
        print("impossible")
        exit()
    print("1" * c + "0" + "1" * b)
    exit()

if d == 0 and a > 0:
    if b + c != a1:
        print("impossible")
        exit()

    print("0" * b + "1" + "0" * c)
    exit()


if (c + b != a1 * d1):
    print("impossible")
    exit()

num_right = c // d1
num_right_m = c % d1

ans = (a1 - num_right - ((num_right_m != 0 ))) * "0" + "1" * (num_right_m) + "0" * (num_right_m!=0) +"1"*(d1 - num_right_m) + num_right * "0"

print(ans)


