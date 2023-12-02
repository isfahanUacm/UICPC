import sys
import time
sys.setrecursionlimit(10**8)

TIME_LIMIT = 0.2 # seconds
START = time.time()

n, s = map(int, sys.stdin.readline().strip().split())
arr = []
for i in range(n):
    name, bet = sys.stdin.readline().strip().split()
    bet = int(bet)
    if bet <= s:
        arr.append((name, bet))

arr = sorted(arr, key=lambda x: -x[1]);

ans = [False]*len(arr)
used = [False]*len(arr)

def output():
    print(sum(ans))
    for i in range(len(arr)):
        if ans[i]:
            print(arr[i][0])
    sys.exit(0)

def bt(i, left):
    if left == 0:
        for j in range(len(arr)):
            if used[j]:
                ans[j] = True
        return
    if i == len(arr):
        return

    if time.time() - START > TIME_LIMIT:
        output()

    if arr[i][1] <= left:
        used[i] = True
        bt(i+1, left - arr[i][1])
        used[i] = False

    bt(i+1, left)

bt(0, s)
output()

