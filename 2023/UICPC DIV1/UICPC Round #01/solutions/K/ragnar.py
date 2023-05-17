n = int(raw_input())
size = 1 << n
l = [int(raw_input()) for _ in range(size)]
l.sort()
cur = [0]
got = []
for _ in range(n):
  v = -1
  for i in range(len(cur)):
    if cur[i] != l[i]:
      v = l[i]
      break
  if v == -1:
    v = l[len(cur)]
  got.append(v)
  for i in range(len(cur)):
    cur.append(cur[i] + v)
  cur.sort()

if cur == l:
  print '\n'.join(str(p) for p in got)
else:
  print 'impossible'
