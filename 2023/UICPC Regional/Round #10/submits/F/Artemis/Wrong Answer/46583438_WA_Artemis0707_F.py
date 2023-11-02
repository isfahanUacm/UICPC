n = int(input())
a1 = []
for _ in range(n):
    a,b = map(int, input().split())
    a1.append((a,b))



a1.sort(key=lambda x: (x[0], x[1]))

g1 = a1[0][0] + a1[len(a1)-1][0]
g2 = a1[0][1] + a1[len(a1)-1][1]

for i in range(1, len(a1)//2):
    if a1[i][0] + a1[len(a1)-i-1][0] != g1 or a1[i][1] + a1[len(a1)-i-1][1] != g2:
        print("impossible")
        exit()

print("possible")


