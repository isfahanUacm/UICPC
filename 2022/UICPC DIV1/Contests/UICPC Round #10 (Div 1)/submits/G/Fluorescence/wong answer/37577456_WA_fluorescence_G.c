n, m = map(int, input().split())

dist = 0
huts = []
peoples = list(map(int, input().split()))
for i in range(n):
    people = peoples[i]
    huts.append([people, dist])
    dist+=100

ice = list(map(int, input().split()))
ice.sort()

iceDe = [[0,0] for i in range(m)]
ic = 0
for i in range(n):
    numP = huts[i][0]
    posHut = huts[i][1]
    if ic<m:
        posIce = ice[ic]
    if posHut>=posIce and ic<m:
        ic+=1
    if posHut == posIce:
        continue
    if ic==0:
        posIceLeft = -(10**9)
    else:
        posIceLeft = ice[ic-1]
    if ic<m:
        posIceRight = ice[ic]
    else:
        posIceRight = 10**9
    #distance from previose icecream shop
    distanceLeft = posHut - posIceLeft
    #distance from current icecream shop
    distanceRight = posIceRight - posHut
    if distanceLeft<distanceRight:
        iceDe[ic-1][1]+= numP
    else:
        iceDe[ic][0] += numP
#print(iceDe)
maxi = iceDe[0][0]
for i in range(m-1):
    total = iceDe[i][1] + iceDe[i+1][0]
    maxi = max(maxi, total)
maxi = max(maxi, iceDe[m-1][1])
print(maxi)