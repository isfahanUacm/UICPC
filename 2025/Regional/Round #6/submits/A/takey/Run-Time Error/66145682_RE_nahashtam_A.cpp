#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdint>

using namespace std;

class LazySegmentTree {
private:
    int n;
    int size;
    vector<bool> tree;      // Stores AND of all values in the segment
    vector<int8_t> lazy;    // -1 = no lazy, 0 = false, 1 = true
    
    void propagate(int node, int start, int end) {
        if (lazy[node] != -1) {
            tree[node] = (lazy[node] == 1);
            
            if (start != end) {
                lazy[node * 2] = lazy[node];
                lazy[node * 2 + 1] = lazy[node];
            }
            
            lazy[node] = -1;
        }
    }
    
    void updateRange(int node, int start, int end, int l, int r, bool value) {
        propagate(node, start, end);
        
        if (start > r || end < l) {
            return;
        }
        
        if (l <= start && end <= r) {
            lazy[node] = (value ? 1 : 0);
            propagate(node, start, end);
            return;
        }
        
        int mid = (start + end) / 2;
        updateRange(node * 2, start, mid, l, r, value);
        updateRange(node * 2 + 1, mid + 1, end, l, r, value);
        
        tree[node] = tree[node * 2] && tree[node * 2 + 1];
    }
    
    int64_t countTrue(int node, int start, int end) {
        propagate(node, start, end);
        
        if (tree[node]) {
            return (end - start + 1);
        }
        
        if (start == end) {
            return tree[node] ? 1 : 0;
        }
        
        int mid = (start + end) / 2;
        int64_t leftCount = countTrue(node * 2, start, mid);
        int64_t rightCount = countTrue(node * 2 + 1, mid + 1, end);
        
        return leftCount + rightCount;
    }
    
public:
    LazySegmentTree(int n) : n(n), size(4 * n) {
        tree.resize(size, true);
        lazy.resize(size, -1);
    }
    
    void updateRange(int l, int r, bool value) {
        if (l > r || l < 0 || r >= n) {
            throw invalid_argument("Invalid range");
        }
        updateRange(1, 0, n - 1, l, r, value);
    }
    
    int64_t countTrueLeaves() {
        if (n < 1) return 0;
        return countTrue(1, 0, n - 1);
    }
};

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, dummy1, y_s, dummy2, y_f;
    cin >> n >> dummy1 >> y_s >> dummy2 >> y_f;
    
    int y_l = y_s - y_f;
    LazySegmentTree lst(y_l);
    
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int left = max(0, y1 - y_f);
        int right = min(y_l - 1, y2 - y_f - 1);
        
        if (left <= right) {
            lst.updateRange(left, right, false);
        }
    }
    
    cout << lst.countTrueLeaves() << ".0\n";
    
    return 0;
}