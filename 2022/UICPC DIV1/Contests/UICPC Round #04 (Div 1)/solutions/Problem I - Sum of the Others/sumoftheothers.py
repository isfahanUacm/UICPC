import sys

inp = sys.stdin.readlines()
for line in inp:
    li = list(map(int, line.split()))
    s = sum(li)
    for i in range(len(li)):
        if s == 2 * li[i]:
            print(li[i])
            break

