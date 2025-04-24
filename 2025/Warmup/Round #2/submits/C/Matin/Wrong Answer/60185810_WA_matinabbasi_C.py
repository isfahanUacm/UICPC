# for _ in range(int(input())):
#     n, c = map(int, input().split())
#     a = list(map(int, input().split()))
    



n= int(input()) 
parantez = input()

stack = []

cnt= 0
for a in parantez:
    if (a=="("):
        stack.append("(")
    else:
        stack.pop()
        cnt+=1

print(cnt)
