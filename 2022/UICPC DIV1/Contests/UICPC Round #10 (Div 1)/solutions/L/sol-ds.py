
NB_RADII, NB_ANGLES = 20, 360

def solve(walls):
  
  circular = [[False] * NB_ANGLES for _ in range(NB_RADII)]
  straight = [[False] * NB_ANGLES for _ in range(NB_RADII-1)]
  for w,a,b,c in walls:
    if w == "C":
      if c<b: c += NB_ANGLES
      for i in range(b,c):
        circular[a-1][i%NB_ANGLES] = True
    if w == "S":
      for i in range(a,b):
        straight[i-1][c] = True
  
  NB_NODES = NB_ANGLES*(NB_RADII-1)+2
  tab = [i for i in range(NB_NODES)]
  def find(i):
    if tab[i] != i:
      tab[i] = find(tab[i])
    return tab[i]
  
  source, target = NB_NODES-2, NB_NODES-1
  for r in range(NB_RADII-1):
    for t in range(NB_ANGLES):
      if not straight[r][t]:
        a, b = r*NB_ANGLES+t, r*NB_ANGLES+t-1
        if t == 0: b = r*NB_ANGLES+NB_ANGLES-1
        tab[find(a)] = find(b)
  for r in range(NB_RADII):
    for t in range(NB_ANGLES):
      if not circular[r][t]:
        a, b = (r-1)*NB_ANGLES+t, r*NB_ANGLES+t
        if r == 0: a = source
        if r == NB_RADII-1: b = target
        tab[find(a)] = find(b)
  if find(source) == find(target):
    print("YES")
  else:
    print("NO")

if __name__ == "__main__":
  t = int(input())
  for _ in range(t):
    n = int(input())
    walls = []
    for _ in range(n):
      wall = input().strip().split()
      walls.append([wall[0]]+list(map(int,wall[1:])))
    solve(walls)
