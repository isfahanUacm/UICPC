a , b = map(int, input().split())

input = list(map(int, input().split()))

maximum = input[0]
for i in input:
    if i>0:
        b += i
    if i>maximum:
        maximum = i
if (b + maximum)<0:
    print(-1)
else:
    print(b)