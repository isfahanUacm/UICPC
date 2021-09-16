h, w = [], []
hh, ww = map(int, input().split())
h.append(hh)
w.append(ww)
hh, ww = map(int, input().split())
h.append(hh)
w.append(ww)
hh, ww = map(int, input().split())
h.append(hh)
w.append(ww)
if (h[0] == h[1] == h[2] and sum(w) == h[0]) or (h[0] == w[1] + w[2] and h[1] == h[2] and w[0] + h[1] == h[0]) or (h[0] == h[1] + h[2] and w[1] == w[2] and w[0] + w[1] == h[0]) or (h[0] == h[1] + w[2] and w[1] == h[2] and w[0] + w[1] == h[0]) or (h[0] == w[1] + h[2] and h[1] == w[2] and w[0] + h[1] == h[0]):
    print('YES')
else:
    print('NO')