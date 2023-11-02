from math import sin,cos
p,a,b,c,d,n = map(int,input().split())

def price(k):
    return p*(sin(a*k+b)+cos(c*k+d)+2)

max_price = 0
max_diff = 0
for i in range(1,n+1):
    max_price = max(max_price,price(i))
    max_diff = max(max_diff,max_price-price(i))

print(max_diff)