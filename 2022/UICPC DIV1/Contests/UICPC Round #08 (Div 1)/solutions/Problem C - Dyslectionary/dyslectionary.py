
import sys
lines = sys.stdin.readlines()
li = []
mx = 0
for line in lines:
    if line == '\n':
        li.sort(key=lambda x: x[::-1])
        # print(li)
        for a in li:
            print((' ' * (mx - len(a))) + a)
        print()
        li = []
        mx = 0
        continue
    li.append(line.strip())
    mx = max(mx, len(li[-1]))

li.sort(key=lambda x: x[::-1])
for a in li:
    print((' ' * (mx - len(a))) + a)