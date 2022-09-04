word = list(input().split())
for i in word:
    if word.count(i) > 1:
        print("no")
        exit()

print("yes")
