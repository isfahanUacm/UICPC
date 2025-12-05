class LazySegmentTree:
    def __init__(self, n):
        self.n = n
        self.size = 4 * n 
        self.tree = [True] * self.size  
        self.lazy = [None] * self.size  
    
    def _propagate(self, node, start, end):
        if self.lazy[node] is not None:
            self.tree[node] = self.lazy[node]
            
            if start != end:
                self.lazy[2 * node] = self.lazy[node]
                self.lazy[2 * node + 1] = self.lazy[node]
            
            self.lazy[node] = None
    
    def _update_range(self, node, start, end, l, r, value):

        self._propagate(node, start, end)
        
        if start > r or end < l:
            return
        
        if l <= start and end <= r:
            self.lazy[node] = value
            self._propagate(node, start, end)
            return
        
        mid = (start + end) // 2
        self._update_range(2 * node, start, mid, l, r, value)
        self._update_range(2 * node + 1, mid + 1, end, l, r, value)
        
        self.tree[node] = self.tree[2 * node] and self.tree[2 * node + 1]
    
    def update_range(self, l, r, value):
        if l > r or l < 0 or r >= self.n:
            raise ValueError("Invalid range")
        self._update_range(1, 0, self.n - 1, l, r, value)
    
    def _count_true(self, node, start, end):
        self._propagate(node, start, end)
        
        if self.tree[node]:
            return (end - start + 1)
        
        if start == end:
            return 1 if self.tree[node] else 0
        
        mid = (start + end) // 2
        left_count = self._count_true(2 * node, start, mid)
        right_count = self._count_true(2 * node + 1, mid + 1, end)
        
        return left_count + right_count
    
    def count_true_leaves(self):
        if self.n < 1:
            return 0
        return self._count_true(1, 0, self.n - 1)



n, _, y_s, _, y_f = map(int, input().split())
y_l = y_s - y_f
lst = LazySegmentTree(y_l)
for i in range(n):
    _, y1, _, y2 = map(int, input().split())
    left = max(0, y1 - y_f)
    right = min(y_l - 1, y2 - y_f - 1)
    if left <= right:
        lst.update_range(left, right, False)

print(str(lst.count_true_leaves())+'.0')
