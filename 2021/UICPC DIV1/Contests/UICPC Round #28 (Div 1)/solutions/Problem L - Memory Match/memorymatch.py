n = int(input())
m = int(input())

cards = {}
for i in range(m):
    c1, c2, p1, p2 = map(str, input().split())
    if p1 == p2:
        if p1 in cards:
            cards.pop(p1)
        n -= 2
        continue
    if p1 in cards:
        if len(cards[p1]) < 2:
            if c1 not in cards[p1]:
                cards[p1].append(c1)
    else:
        cards[p1] = [c1]
    if p2 in cards:
        if len(cards[p2]) < 2:
            if c2 not in cards[p2]:
                cards[p2].append(c2)
    else:
        cards[p2] = [c2]
score = 0
seen = 0
for k in cards:
    if len(cards[k]) == 2:
        score += 1
        n -= 2
    else:
        seen += 1
if n == 2:
    print(score+1)
elif seen == n - seen:
    print(score + seen)
else:
    print(score)
