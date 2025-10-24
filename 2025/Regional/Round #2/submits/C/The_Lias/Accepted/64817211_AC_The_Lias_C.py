a = int (input())
b = int (input())
c = a * b

if a < 2147483648:
    a = 32
elif  a < 9223372036854775808:
    a = 64
else:
    a = 128

if b < 2147483648:
    b = 32
elif  b < 9223372036854775808:
    b = 64
else:
    b = 128

if c < 2147483648:
    c = 32
elif  c < 9223372036854775808:
    c = 64
else:
    c = 128

if c == 128 and b == 64 and a == 32:
    b = 128
elif c > b and c > a:
    a = c
print (f"{a}\n{b}\n{c}")