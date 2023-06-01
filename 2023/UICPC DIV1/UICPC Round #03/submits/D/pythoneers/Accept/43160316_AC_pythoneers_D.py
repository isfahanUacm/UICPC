nTrucks = int(input())
locs = []
sumOfS1 = 0
sumOfA = 0
for i in range(nTrucks):
    s, a = list(map(int, input().split(' ')))
    sumOfS1 += s
    sumOfA += a
    locs.append([s, a])

#def dist(s1, s2, a1, a2):
  #  return abs(s1 - s2) + abs(a1 - a2)

locs.sort(key= lambda x: x[0], reverse=True)
answer = (sumOfS1 + sumOfA) * len(locs)
j = 1
for i in range(nTrucks):
    answer -= j * locs[i][0]
    j += 2


locs.sort(key= lambda x: x[1], reverse=True)

k = 1
for i in range(nTrucks):
    answer -= k * locs[i][1]
    k += 2

print(answer)
