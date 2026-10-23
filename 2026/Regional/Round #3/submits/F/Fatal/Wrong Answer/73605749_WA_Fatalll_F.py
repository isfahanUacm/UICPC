t = int(input())
for i in range(t):
    s = input()
    if s.count(s[0]) == len(s):
        print(0)
    else:
        if(len(s) % 2 == 0):
            if(s[0: (len(s)//2)] == s[(len(s)//2): len(s)]):
                print((len(s) * 2) - 2)
                break
        else:
            if(s[0:(len(s)//2)] == reversed(s[(len(s)//2 + 1) : len(s)])):
                print((len(s)*2)-2)
                break
        print(len(s))