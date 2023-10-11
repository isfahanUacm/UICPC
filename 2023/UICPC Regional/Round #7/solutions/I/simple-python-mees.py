import sys

a = int(sys.stdin.readline())

if a == 1:
    print "NO"
    sys.exit(0)

for i in range(2,int(a**0.5) + 1):
    if a % i == 0:
        while a % i == 0:
            a /= i
        if a == 1:
            print "YES"
        else:
            print "NO"
        sys.exit(0)
print "YES"
