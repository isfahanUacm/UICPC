N, M = map(int, input().split())

G = []
for i in range(N):
    G.append(input())

RightNeed = [[False for j in range(M)] for i in range(N)]
BottomNeed = [[False for j in range(M)] for i in range(N)]

for i in range(N):
    for j in range(M):

        LeftNeed = False if not j else RightNeed[i][j - 1]
        UpNeed = False if not i else BottomNeed[i - 1][j]

        if G[i][j] == 'A':
            if LeftNeed or UpNeed:
                print('Impossible')
                exit(0)
        elif G[i][j] == 'B':
            if (LeftNeed and UpNeed) or (not LeftNeed and not UpNeed):
                print('Impossible')
                exit(0)
            RightNeed[i][j] = LeftNeed
            BottomNeed[i][j] = UpNeed
        elif G[i][j] == 'C':
            RightNeed[i][j] = not LeftNeed
            BottomNeed[i][j] = not UpNeed
        else:
            if not LeftNeed or not UpNeed:
                print('Impossible')
                exit(0)
            RightNeed[i][j] = BottomNeed[i][j] = True
        
        if (i == N - 1 and BottomNeed[i][j]) or (j == M - 1 and RightNeed[i][j]):
            print('Impossible')
            exit(0)

print('Possible')