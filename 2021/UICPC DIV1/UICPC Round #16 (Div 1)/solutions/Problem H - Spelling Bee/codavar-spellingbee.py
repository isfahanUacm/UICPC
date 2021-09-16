s = input()
n = int(input())
for i in range(n):
    word = input()
    if len(word) >= 4 and s[0] in word:
        flag = True
        for ch in word:
            if ch not in s:
                flag = False
                break
        if flag:
            print(word)
