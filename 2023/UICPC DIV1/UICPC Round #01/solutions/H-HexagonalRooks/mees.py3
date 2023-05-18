S, G = input().split()

S = (ord(S[0]), int(S[1:]))
G = (ord(G[0]), int(G[1:]))

ct = 0

def can_reach(s, t):
    scol, srow = s
    tcol, trow = t

    if s == t:
        return False
    if scol == tcol:
        return True

    # Put both the row-numbers in canonical (left-of-f) value
    if scol > ord('f'):
        srow += scol - ord('f')
    if tcol > ord('f'):
        trow += tcol - ord('f')

    if srow == trow:
        return True

    if (srow - trow) == (scol - tcol):
        return True

    return False

for col in range(ord('a'), ord('l')):
    for n in range(1, 12):
        height = 11 - abs(col - ord('f'))
        if n > height:
            break
        # print("Field:", (chr(col), n), end='')
        if can_reach(S, (col, n)) and can_reach((col, n), G):
            # print("Y")
            ct += 1
print(ct)

