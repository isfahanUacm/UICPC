t = int(input())
for i in range(t):
    inpt = input()
    if '+' not in inpt:
        print('skipped')
    else:
        a = int(inpt.split('+')[0])
        b = int(inpt.split('+')[1])
        print(a+b)

