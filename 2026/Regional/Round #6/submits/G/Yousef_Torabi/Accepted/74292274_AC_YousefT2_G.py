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
elif b+maximum == 0:
    print(0)
elif maximum<0:
    print(b+maximum)
else:
    print(b)