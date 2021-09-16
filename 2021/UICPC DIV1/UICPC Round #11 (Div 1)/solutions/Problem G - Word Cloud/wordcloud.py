import math
cnt = 1
while True:
    w, n = map(int, input().split())
    if w == n == 0:
        break
    li = []
    mxo = 0
    for i in range(n):
        inpli = input().split()
        ch, oc = len(inpli[0]), int(inpli[1])
        mxo = max(oc, mxo)
        li.append((ch, oc))
    for i in range(n):
        h = 8 + int(math.ceil(40 * (li[i][1] - 4) / (mxo - 4)))
        wordw = int(math.ceil(9 * h * li[i][0] / 16))
        li[i] = (h, wordw)
    res = 0
    consw = 0
    curh = 0
    for i in range(n):
        if consw + li[i][1] <= w:
            consw += li[i][1] + 10
            curh = max(curh, li[i][0])
        else:
            res += curh
            curh = li[i][0]
            consw = li[i][1] + 10
    print('CLOUD ' + str(cnt) + ': ' + str(res + curh))
    cnt += 1
