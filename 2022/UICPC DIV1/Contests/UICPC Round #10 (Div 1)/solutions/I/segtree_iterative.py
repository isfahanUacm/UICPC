from collections import deque
 
 
class SegmentTree:    
    def __init__(self, initial_values):
        self.len = 1
        self.n = len(initial_values)
        while self.len < self.n: self.len *= 2
        self.tt = [0] * (2*self.len)
        for i in range(self.n):
            self.tt[self.len + i] = initial_values[i]
        for i in range(self.len-1, 0, -1):
            self.tt[i] = max(self.tt[2*i], self.tt[2*i+1])
    
    def remove(self, i):
        i += self.len
        self.tt[i] = -(1<<20)
        while i != 1:
            i >>= 1
            self.tt[i] = max(self.tt[2*i], self.tt[2*i+1])

    def find_max(self, v):
        while v < self.len:
            if self.tt[2*v] > self.tt[2*v+1]:
                v = 2*v
            else:
                v = 2*v+1
        return v - self.len

    def find_larger(self, l, r, x):
        l = max(l, 0)
        r = min(r, self.n-1)

        l += self.len
        r += self.len + 1
        
        while l < r:
            if l & 1:
                if self.tt[l] >= x:
                    return self.find_max(l)
                l += 1
            if r & 1:
                r -= 1
                if self.tt[r] >= x:
                    return self.find_max(r)
            l >>= 1
            r >>= 1
        return -1

import sys
input = sys.stdin.buffer.readline

def solve():
    n, a, b = map(int, input().split())
    p = list(map(int, input().split()))
    a -= 1
    b -= 1
    
    SR = SegmentTree([p[i] - i for i in range(n)])
    SL = SegmentTree([p[i] + i for i in range(n)])

    
    dist = [n]*n
    q = deque()
    
    def relax_edge(v, u):
        dist[u] = dist[v] + 1
        q.append(u)
        SR.remove(u)
        SL.remove(u)
        return True
    
    dist[a] = -1
    assert(relax_edge(a, a))

    while q:
        v = q.popleft()
        while True:
            u = SR.find_larger(v, v + p[v], -v)
            if u == -1:
                break
            relax_edge(v, u)
        while True:
            u = SL.find_larger(v - p[v], v, v)
            if u == -1:
                break
            relax_edge(v, u)
    
    print(dist[b])
 
 
 
t = int(input())
for _ in range(t):
    solve()
