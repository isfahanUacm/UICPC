n = input().split()
for i in n:
    num = n.count(i)
    if num > 1:
        print("no")
        break
else:
    print("yes")
