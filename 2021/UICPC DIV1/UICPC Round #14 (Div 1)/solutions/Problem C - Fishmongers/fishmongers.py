n, m = map(int, input().split())
fish = list(map(int, input().split()))
buyers = []
for i in range(m):
    x, p = map(int, input().split())
    buyers.append([p, x])
buyers.sort(reverse=True)
fish.sort(reverse=True)
res = 0
it = 0
for f in fish:
    while it < len(buyers) and not buyers[it][1]:
        it += 1
    if it == len(buyers):
        break
    res += f * buyers[it][0]
    buyers[it][1] -= 1
print(res)
