N, M = map(int, input().split())
hut = list(map(int, input().split()))
shop = list(map(int, input().split())) if M > 0 else []
shop = sorted([-1e9] + shop + [1e9])

events = []
j = 0
for i in range(N):
  while shop[j] < 100*i:
    j += 1
  if shop[j] != 100 * i:
    assert(shop[j-1] < 100*i < shop[j])
    d = min(100*i - shop[j-1], shop[j] - 100*i)
    events.append((100*i-d, hut[i]))
    events.append((100*i+d, -hut[i]))

best, act = 0, 0
for x,delta in sorted(events):
  act += delta
  best = max(best, act)
print(best)
