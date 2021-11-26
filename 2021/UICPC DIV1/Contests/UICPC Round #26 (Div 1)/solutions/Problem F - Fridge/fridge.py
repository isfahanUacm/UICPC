li = [0 for i in range(10)]
s = input()
for i in range(len(s)):
    li[int(s[i])] += 1
for i in range(1, 200):
    if i > 1:
        if li[0] < i-1:
            print('1'+'0'*(i-1))
            exit(0)
    for j in range(1, 10):
        if li[j] < i:
            print(i*str(j))
            exit(0)