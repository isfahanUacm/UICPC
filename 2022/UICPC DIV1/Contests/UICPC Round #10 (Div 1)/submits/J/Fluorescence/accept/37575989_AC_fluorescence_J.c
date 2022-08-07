for TestCase in range(int(input())):
    b,c = map(int,input().split())
    maxW = 0
    maxR = 0
    for i in range(c):
        red, white = map(int, input().split())
        maxR = max(maxR, red)
        maxW = max(maxW,white)
    if maxR+maxW>b:
        print("IMPOSSIBLE")
    elif maxR>maxW:
        s = 'R'*maxR
        s+= 'W'*(b-maxR)
        print(s)
    else:
        s = 'W'*maxW
        s+= 'R'*(b-maxW)
        print(s)