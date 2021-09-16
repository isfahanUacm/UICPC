res = 20002
n = int(input())
li = [int(input()) for i in range(n)]
if n == 2:
    for i in range(n):
        res = min(res, 2*li[i])
elif n == 3:
    for i in range(n):
        res = min(res, li[i]+li[(i+1)%n])
else:
    for i in range(n):
        res = min(res, li[i]+li[(i+2)%n])
print(res)