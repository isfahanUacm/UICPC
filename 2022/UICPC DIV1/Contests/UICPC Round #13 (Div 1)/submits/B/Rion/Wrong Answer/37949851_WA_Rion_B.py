n = int(input())
roads = []
for i in range(n):
    line = [int(item) for item in input().split()]
    min_value = line[0]
    for q in line:
        if q != 0 and q < min_value:
            min_value = q
    # print(min_value)
    ans = [z + 1 for z, x in enumerate(line) if x == min_value]
    # print(line)
    for j in ans:
        # print(j, i + 1)
        if i + 1 != j:
            roads.append({j, i + 1})
s = set(frozenset(i) for i in roads)
for a, b in s:
  print(a, b)