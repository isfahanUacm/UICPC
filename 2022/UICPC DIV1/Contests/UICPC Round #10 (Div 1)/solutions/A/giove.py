from collections import defaultdict


t = int(input())

for _ in range(t):
    n = int(input())
    beauties = defaultdict(list)

    for i in range(n):
        b, d = map(int, input().strip().split())
        beauties[d].append(b)

    if len(beauties) < 10:
        print("MOREPROBLEMS")

    else:
        print(sum(max(x) for x in beauties.values()))

