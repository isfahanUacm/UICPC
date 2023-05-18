import sys

n, m = [int(x) for x in raw_input().split()]
forward = []
backward = []
for i, line in enumerate(sys.stdin):
    a, b = [int(x) for x in line.split()]
    if a < b:
        forward.append(i+1)
    else:
        backward.append(i+1)

if len(forward) < len(backward):
    print(len(forward))
    print("\n".join([str(i) for i in forward]))
else:
    print(len(backward))
    print("\n".join([str(i) for i in backward]))
