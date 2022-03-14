li = [0 for i in range(26)]
res1 = 0
res2 = 0
while True:
    inp = input()
    if inp == '-1':
        break
    t, q, r = inp.split()
    t = int(t)
    index = ord(q[0]) - ord('A')
    if r == 'right':
        res1 += 1
        res2 += t + 20 * li[index]
    else:
        li[index] += 1
print(res1, res2)
