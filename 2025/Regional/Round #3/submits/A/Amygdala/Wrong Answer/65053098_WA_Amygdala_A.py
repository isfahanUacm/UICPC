d = int(input())
a, b = map(int, input().split())
da, db = map(int , input().split())

da *= d
db *= d

a -= da
b -= db
b += a

print(a, b)

print((a / b) * 100)