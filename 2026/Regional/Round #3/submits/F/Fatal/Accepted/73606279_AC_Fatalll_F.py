t = int(input())
for i in range(t):
    s = input()
    if s.count(s[0]) == len(s):
        print(0)
    else:
        print((len(s) * 2) - 2)