a, b = input().split()
a = int(a)
b = int(b)
result = a * b

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True
def full_square(result):
    i = 1
    while ((i ** 2) < result):
        i += 1
        if (result % (i ** 2) == 0):
            return True;

        if( (i**2) > result ):
            return False;
if(is_prime(a) and is_prime(b) and a!=b) :
    print("full credit")
else :
    if (not full_square(result)):
        print("partial credit")
    else:
        print("no credit")
