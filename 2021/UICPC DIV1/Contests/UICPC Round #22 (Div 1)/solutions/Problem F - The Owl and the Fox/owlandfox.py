t = int(input())
for i in range(t):
    n = [int(ch) for ch in input()]
    for d in reversed(range(len(n))):
        if n[d]:
            n[d] -= 1
            break
    print(int(''.join([str(ch) for ch in n])))
