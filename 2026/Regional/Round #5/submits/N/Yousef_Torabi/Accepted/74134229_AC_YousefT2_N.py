n = int(input())

if n%2 == 0:
    print(int(n*(n+2)/4))
else:
    print(int(((n//2)+1)**2))