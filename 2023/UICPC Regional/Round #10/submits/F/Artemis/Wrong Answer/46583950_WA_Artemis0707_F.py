n = int(input())
a1 = []
a_avg = 0
b_avg = 0
used = {}
for _ in range(n):
    a,b = map(int, input().split())
    a_avg += a
    b_avg += b
    if (a,b) not in used:
        used[(a,b)] = 1
    else:
        used[(a,b)] += 1
    a1.append((a,b))

a_avg /= (n//2)
b_avg /= (n//2)
a_avg = int(a_avg)
b_avg = int(b_avg)
#print(used)
for i in range(n):
    #print(f"{i}, {used}")
    if used[(a1[i][0], a1[i][1])] == 0:
        continue

    remain_a = a_avg - a1[i][0]
    remain_b = b_avg - a1[i][1]

    remain = (remain_a, remain_b)
    #print(remain)
    if remain in used and used[remain] > 0 :
        used[remain] -= 1
        used[(a1[i][0], a1[i][1])] -=1
    else:
        print("impossible")
        exit()

print("possible")
        






