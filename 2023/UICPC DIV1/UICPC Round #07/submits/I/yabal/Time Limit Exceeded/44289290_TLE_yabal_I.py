s = 1
e = 1

firstline = input().split()
n = int(firstline[0])
c = int(firstline[1])

second = input().split()
w = []
for i in second:
    w.append(int(i))

def wsum():
    answer = 0
    for i in range(s-1,e+1):
        answer += w[i]
    return answer

x = []
y = []

x.append(s)
y.append(e)

while s <= n:
    if e+1 > n:
        s += 1
    elif wsum() > c:
        s += 1
    else:
        e += 1
    x.append(s)
    y.append(e)

for i in range(1,n+1):
    count = 0
    for j in range(len(x)):
        if i >= x[j] and i <= y[j]:
                count +=1

    print(count)