n = int(input())
import math

powerTwo = [2]
for i in range(50):
    powerTwo.append(powerTwo[i] * 2)

for i in range(n):
    total, my, you, p = map(int, input().split(' '))
    p /= 100
    
    nWin = total // 2 + 1
    nRem = total - my - you
    
    if you >= nWin:
        print("RECOUNT!")
    elif my >= nWin:
        print("GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!")
    elif nRem == 0:
        print("PATIENCE, EVERYONE!")
    else:
        remWin = nWin - my
        val = 0
        for i in range(remWin, nRem + 1):
            val += math.comb(nRem, i)
         
        pWin = val / powerTwo[nRem - 1]
        if pWin > p:
            print("GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!")
        else:
            print("PATIENCE, EVERYONE!")
    
    
