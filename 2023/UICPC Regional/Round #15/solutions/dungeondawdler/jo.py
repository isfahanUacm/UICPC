F='NESW'
D=[(-1,0),(0,1),(1,0),(0,-1)]
add=lambda X, Y: (X[0] + Y[0], X[1] + Y[1])
sub=lambda X, Y: (X[0] - Y[0], X[1] - Y[1])
step=lambda X, i: add(X, D[i])
rev=lambda A:map(lambda x:(x+2)%4, A[::-1])

class State:
    def __init__(S, U):
        S.x = (0,0)
        S.path = []
        S.G = {S.x:'.'}
        S.seen = set([S.x])
        S.visited = set()
        S.visit(U)

    def visit(S, U):
        S.visited.add(S.x)
        for i,v in enumerate(U):
            p = step(S.x, i)
            if not p in S.seen:
                S.seen.add(p)
                S.G[p] = v
        if S.G[S.x] == '.':
            S.G[S.x] = ":"

    def print_ans(S):
        c0=c1=r0=r1=0
        M=dict([(k,'.'if v==':'else v)for k,v in S.G.items()])
        for r,c in M.keys():
            c0,c1,r0,r1=min(c0,c),max(c1,c),min(r0,r),max(r1,r)
        print 'done\n%d %d'%(r1-r0+1,c1-c0+1)
        for r in range(r0, r1+1):
            print ''.join([M.get((r,c), '#') for c in range(c0, c1+1)])

    def go(S, s):
        print F[s]
        ln=raw_input().split()
        S.x = step(S.x, s)
        S.visit(ln[0])
        if ln[1] == 'trap':
            S.trap = S.x
            return State(ln[2])

    def search(S, no=[]):
        while True:
            s = None
            for i in range(4):
                p = step(S.x, i)
                if p not in no and p not in S.visited and S.G[p] != '#':
                    s = i
                    break
            if s is None:
                if not S.path: break
                s = (S.path[-1]+2)%4
                del S.path[-1]
            else:
                S.path += [s]
            succ = S.go(s)
            if succ: return succ

    def walk(S, path):
        for s in path:
            p = step(S.x, s)
            if S.G.get(p, '#') == '#': break
            S.path += [s]
            succ = S.go(s)
            if succ: return succ

def merge(A, B, off):
    for rc in B:
        A[add(rc, off)] = B[rc]

def solve(S, A, ab, pab, ba, pba):
    T = [ab]
    Am = A.search(no=T)
    if Am:
        T += [A.trap]
        Am.search(no=T)
        Bm = Am.walk(pab)
    else:
        Am, Bm = A, A.walk(pab)
    B = Bm.search(no=[ba])
    if B:
        B.search(no=[ba, Bm.trap])
        Bm = B
    Bm.walk(pba)
    if len(T) == 2:
        O = sub(T[1], ba)
        S0 = sub(T[1], S.trap)
    else:
        for rc,v in Bm.G.iteritems():
            if v == '.':
                O = sub(T[0], rc)
                break
        S0 = sub(add(O, ba), S.trap)
    merge(Am.G, Bm.G, O)
    Am.G[add(O, ba)] = 'A'
    Am.G[T[0]] = 'B'
    Am.G[(0,0)] = 'a'
    Am.G[O] = 'b'
    Am.G[S0] = 'S'
    Am.print_ans()

def solve_in(S, wx, wy, T, P):
    disc = wx.path
    b = wy.walk(disc)
    if b:
        a = b.search(no=[wx.trap])
        ab = a.walk(P[0])
        bx = ab.walk(disc)
        if bx:
            ax = bx.walk(b.path)
            solve(S, ax, T[0], P[0], b.trap, b.path)
        else:
            ab.walk(rev(ab.path))
            solve(S, ab, T[1], P[1], b.trap, b.path)
    else:# ? => P[0] = A->A
        wy.walk(rev(wy.path))
        solve(S, wy, T[1], P[1], wx.trap, wx.path)

def solve_out(S, wx, T, P, i):
    disc = P[i]
    wy = wx.search()
    z = wy.walk(disc)
    if not z:
        z = wy.search(no=[wx.trap])
        w1 = z.walk(P[0])
        w2 = w1.walk(disc)
        if w2:
            if disc == P[1]:
                w2 = w2.walk(wy.path)
            solve(S, w2, T[1], P[1], wy.trap, wy.path)
        else:
            z = w1.walk(rev(w1.path) + wy.path)
            solve(S, z, T[0], P[0], wy.trap, wy.path)
    else:
        w1 = z.walk(disc)
        if w1:
            solve(S, w1, T[1-i], P[1-i], wx.trap, wx.path)
        else:
            z = z.walk(rev(z.path) + wx.path)
            solve(S, z, T[i], P[i], wx.trap, wx.path)

S = State(raw_input().split()[0])
A = S.search()
if not A:
    S.G[S.x] = 'S'
    S.print_ans()
else:
    B = A.search()
    C = B.walk(A.path)
    if C and B.path == A.path:
        wx = C.search(no=[A.trap])
        if not wx:
            wx = C.walk(A.path)
            wy = wx.search(no=[A.trap])
            if not wy:
                tA = A.trap
                O = sub(tA, S.trap)
                merge(C.G, S.G, O)
                C.G[tA] = 'A'
                C.G[(0,0)] = 'a'
                C.G[O] = 'S'
                C.print_ans()
            else:
                solve_in(S, wx, wy, [A.trap, C.trap], [A.path, C.path])
        else:
            T, P = [A.trap, C.trap], [A.path, C.path]
            for i in [0,1]:
                wy = wx.walk(P[i])
                if not wy or wx.path != P[i]:
                    break
                wx = wy
            if not wy:
                solve_out(S, wx, T, P, i)
            elif wx.path != P[i]:
                solve_in(S, wx, wy, T, P)
    else:
        if not C:
            C = B.search()
        wx = C.walk(A.path)
        if wx and A.path == C.path:
            wy = wx.search(no=[B.trap])
            if not wy: wy = wx
            z = wy.walk(B.path)
            solve(S, z, A.trap, A.path, B.trap, B.path)
        else:
            if wx: C = wx
            z = C.search(no=[B.trap])
            solve(S, z, A.trap, A.path, C.trap, C.path)
