n, m, k = map(int, input().split())
plots = sorted([a * a for a in list(map(int, input().split()))])
houses = [b * b for b in list(map(int, input().split()))]
houses += [((c * 2 ** 0.5) / 2) ** 2 for c in list(map(int, input().split()))]
houses.sort()
j = res = 0
for i in range(m+k):
    while j < n and houses[i] >= plots[j]:
        j += 1
    if j == n:
        break
    res += 1
    j += 1
print(res)
