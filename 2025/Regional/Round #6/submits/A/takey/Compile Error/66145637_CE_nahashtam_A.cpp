#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlong long int>

using namespace std;

class LazySegmentTree {
private:
    long long int n;
    long long int size;
    vector<bool> tree;      // Stores AND of all values in the segment
    vector<long long int8_t> lazy;    // -1 = no lazy, 0 = false, 1 = true
    
    void propagate(long long int node, long long int start, long long int end) {
        if (lazy[node] != -1) {
            tree[node] = (lazy[node] == 1);
            
            if (start != end) {
                lazy[node * 2] = lazy[node];
                lazy[node * 2 + 1] = lazy[node];
            }
            
            lazy[node] = -1;
        }
    }
    
    void updateRange(long long int node, long long int start, long long int end, long long int l, long long int r, bool value) {
        propagate(node, start, end);
        
        if (start > r || end < l) {
            return;
        }
        
        if (l <= start && end <= r) {
            lazy[node] = (value ? 1 : 0);
            propagate(node, start, end);
            return;
        }
        
        long long int mid = (start + end) / 2;
        updateRange(node * 2, start, mid, l, r, value);
        updateRange(node * 2 + 1, mid + 1, end, l, r, value);
        
        tree[node] = tree[node * 2] && tree[node * 2 + 1];
    }
    
    long long int64_t countTrue(long long int node, long long int start, long long int end) {
        propagate(node, start, end);
        
        if (tree[node]) {
            return (end - start + 1);
        }
        
        if (start == end) {
            return tree[node] ? 1 : 0;
        }
        
        long long int mid = (start + end) / 2;
        long long int64_t leftCount = countTrue(node * 2, start, mid);
        long long int64_t rightCount = countTrue(node * 2 + 1, mid + 1, end);
        
        return leftCount + rightCount;
    }
    
public:
    LazySegmentTree(long long int n) : n(n), size(4 * n) {
        tree.resize(size, true);
        lazy.resize(size, -1);
    }
    
    void updateRange(long long int l, long long int r, bool value) {
        if (l > r || l < 0 || r >= n) {
            throw invalid_argument("Invalid range");
        }
        updateRange(1, 0, n - 1, l, r, value);
    }
    
    long long int64_t countTrueLeaves() {
        if (n < 1) return 0;
        return countTrue(1, 0, n - 1);
    }
};

long long int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long int n, dummy1, y_s, dummy2, y_f;
    cin >> n >> dummy1 >> y_s >> dummy2 >> y_f;
    
    long long int y_l = y_s - y_f;
    LazySegmentTree lst(y_l);
    
    for (long long int i = 0; i < n; i++) {
        long long int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        long long int left = max(0, y1 - y_f);
        long long int right = min(y_l - 1, y2 - y_f - 1);
        
        if (left <= right) {
            lst.updateRange(left, right, false);
        }
    }
    
    cout << lst.countTrueLeaves() << ".0\n";
    
    return 0;
}