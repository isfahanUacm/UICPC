n, a, b = map(int, input().split())
print('Alex' if n % (a+b) >= a else 'Barb')