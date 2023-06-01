n = int(input())
a = list()
for i in range (n):
    a.append(int(input()))

if n % 2 ==0:
    result = 0
    for i in range (1, len(a), 2):
        result += (a[i] - a[i-1])
    print(result)
else:
    print('still running')