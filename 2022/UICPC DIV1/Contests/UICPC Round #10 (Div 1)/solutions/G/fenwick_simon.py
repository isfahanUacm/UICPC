def fenwick_sum(tree, i): # return sum(t[:i])
  if i == len(tree)-1: return tree[0]
  res = 0
  while i > 0:
    res += tree[i]
    i -= i & -i
  return res
def fenwick_add(tree, i, v=1): # t[i] += v
  tree[0] += v
  i += 1
  while i < len(tree):
    tree[i] += v
    i += i & -i

if __name__ == "__main__":
  for _ in range(int(input())):
    n = int(input())
    t = list(map(int, input().split()))
    p = [None] * n
    for i in range(n):
      p[t[i]-1] = i
    result = 0
    tree = [0] * (n+1)
    for i in reversed(range(n)):
      if i+1 < n:
        if p[i] < p[i+1]:
          v = fenwick_sum(tree, p[i+1]) \
            - fenwick_sum(tree, p[i])
        else:
          v = fenwick_sum(tree, n) \
            - fenwick_sum(tree, p[i]) \
            + fenwick_sum(tree, p[i+1])
        result += (i+1) * v
      fenwick_add(tree, p[i])
    print(result)

