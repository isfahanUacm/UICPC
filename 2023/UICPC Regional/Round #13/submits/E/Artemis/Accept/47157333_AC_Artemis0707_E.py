n = int(input())
s = list(input().split())

cnt = 0

for i in s:
    cnt +=1
    if i == "mumble":
        continue
    elif int(i) != cnt:
        print("something is fishy")
        exit()

    

print("makes sense")
