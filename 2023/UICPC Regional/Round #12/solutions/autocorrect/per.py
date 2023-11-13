import sys

class Trie:
    def __init__(self):
        self.aut_len = -1
        self.aut_sym = 0
        self.next = [None]*26

    def get_next(self, c, make=False):
        sym = ord(c)-ord('a')
        if make and self.next[sym] is None: self.next[sym] = Trie()
        return self.next[sym]
                

seq = [None]*(1<<20)
opt = [None]*(1<<20)

def solve(word, trie):
    L = 0
    while L < len(word) and trie is not None:
        seq[L] = trie
        trie = trie.get_next(word[L])
        L += 1

    opt[L] = len(word)-L
    nxtb = L
    for i in range(L-1, -1, -1):
        opt[i] = 1 + opt[i+1]
        if i == 0 or seq[i].aut_sym != word[i]:
            nxtb = i
        else:
            opt[i] = min(opt[i], 1 + seq[i].aut_len - (nxtb-i) + opt[nxtb])

    return opt[0];



(n,m) = map(int, sys.stdin.readline().split())
trie = Trie()
for _ in range(n):
    word = sys.stdin.readline().strip()
    node = trie
    idx = 0
    while idx < len(word):
        node = node.get_next(word[idx], make=True)
        idx += 1
        if node.aut_len == -1:
            node.aut_len = len(word)-idx
            node.aut_sym = word[idx] if idx < len(word) else None
    
for _ in range(m):
    print solve(sys.stdin.readline().strip(), trie)
