d = int(input())
a, b = map(int, input().split())
da, db = map(int , input().split())

da *= d
db *= d

a -= da
if a<0:
    a = 0
b -= db
if b<0:
    b = 0
b += a

# print(a, b)

print((a / b) * 100)