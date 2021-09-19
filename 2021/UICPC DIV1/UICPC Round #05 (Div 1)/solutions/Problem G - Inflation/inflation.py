n = int(input())
li = list(map(int, input().split()))
li.sort()
mi = 2
for i in range(n):
    if li[i] > i+1:
        print('impossible')
        exit(0)
    mi = min(mi, li[i]/(i+1))
print(mi)