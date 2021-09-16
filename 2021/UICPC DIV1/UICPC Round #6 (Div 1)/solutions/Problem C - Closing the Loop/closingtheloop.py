t = int(input())
for i in range(1, t+1):
    n = int(input())
    li = input().split()
    bli = []
    rli = []
    for j in range(n):
        if li[j][-1] == 'B':
            bli.append(int(li[j][:-1])-1)
        else:
            rli.append(int(li[j][:-1])-1)
    bli.sort(reverse=True)
    rli.sort(reverse=True)
    m = min(len(bli), len(rli))
    print('Case #%d:' % (i), sum(rli[:m]) + sum(bli[:m]))