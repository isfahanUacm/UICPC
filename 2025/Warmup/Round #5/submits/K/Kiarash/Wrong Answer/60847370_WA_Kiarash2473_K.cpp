#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    struct Node {
        int64_t sum = ~0;

        template <typename M>
        void init(const M &v) {
            sum = v;
        }
    };

    int n;
    vector<Node> tree;

    Node merge(const Node &a, const Node &b) const {
        Node res;
        res.sum = a.sum & b.sum;
        return res;
    }

    inline void pull(int x) {
        tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
    }

    void build(int x, int l, int r) {
        if (l == r) {
            return;
        }
        int m = (l + r) / 2;
        build(2 * x, l, m);
        build(2 * x + 1, m + 1, r);
        pull(x);
    }

    template <typename M>
    void build(int x, int l, int r, const vector<M> &v) {
        if (l == r) {
            tree[x].init(v[l]);
            return;
        }
        int m = (l + r) / 2;
        build(2 * x, l, m, v);
        build(2 * x + 1, m + 1, r, v);
        pull(x);
    }

    template <typename M>
    void modify(int x, int l, int r, int p, const M &v) {
        if (l == r) {
            tree[x].init(v);
            return;
        }
        int m = (l + r) / 2;
        if (p <= m) {
            modify(2 * x, l, m, p, v);
        }
        else {
            modify(2 * x + 1, m + 1, r, p, v);
        }
        pull(x);
    }
    
    Node get(int x, int l, int r, int ll, int rr) {
        if (l > rr || r < ll) {
            return Node();
        }
        if (l >= ll && r <= rr) {
            return tree[x];
        }
        int m = (l + r) / 2;
        return merge(get(2 * x, l, m, ll, rr), get(2 * x + 1, m + 1, r, ll, rr));
    }

    int find_first_knowingly(int x, int l, int r, const function<bool(const Node&)> &f) {
        if (l == r) {
            return l;
        }
        int m = (l + r) / 2;
        if (f(tree[2 * x])) {
            return find_first_knowingly(2 * x, l, m, f);
        } 
        return find_first_knowingly(2 * x + 1, m + 1, r, f);
    }

    int find_first(int x, int l, int r, int ll, int rr, const function<bool(const Node&)> &f) {
        if (l > rr || r < ll) {
            return -1;
        }
        if (l >= ll && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_first_knowingly(x, l, r, f);
        }
        int m = (l + r) / 2;
        int res = find_first(2 * x, l, m, ll, rr, f);
        if (res == -1) {
            res = find_first(2 * x + 1, m + 1, r, ll, rr, f);
        }
        return res;
    }

    int find_last_knowingly(int x, int l, int r, const function<bool(const Node&)> &f) {
        if (l == r) {
            return l;
        }
        int m = (l + r) / 2;
        if (f(tree[2 * x + 1])) {
            return find_last_knowingly(2 * x + 1, m + 1, r, f);
        } 
        return find_last_knowingly(2 * x, l, m, f);
    }

    int find_last(int x, int l, int r, int ll, int rr, const function<bool(const Node&)> &f) {
        if (l > rr || r < ll) {
            return -1;
        }
        if (l >= ll && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_last_knowingly(x, l, r, f);
        }
        int m = (l + r) / 2;
        int res = find_last(2 * x + 1, m + 1, r, ll, rr, f);
        if (res == -1) {
            res = find_last(2 * x, l, m, ll, rr, f);
        }
        return res;
    }

    SegmentTree(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    template <typename M>
    SegmentTree(const vector<M> &v) {
        n = v.size();
        assert(n > 0);
        tree.resize(4 * n);
        build(1, 0, n - 1, v);
    }

    template <typename M>
    void modify(int p, const M &v) {
        assert(p >= 0 && p < n);
        modify(1, 0, n - 1, p, v);
    }

    Node get(int ll, int rr) {
        assert(ll >= 0 && ll <= rr && rr < n);
        return get(1, 0, n - 1, ll, rr);
    }

    Node get(int p) {
        assert(p >= 0 && p < n);
        return get(1, 0, n - 1, p, p);
    }

    // find_first and find_last find first/last element satisfy f
    // auto f = [&](const auto &node) { return node.mn <= 0; };

    int find_first(int ll, int rr, const function<bool(const Node&)> &f) {
        assert(ll >= 0 && ll <= rr && rr < n);
        return find_first(1, 0, n - 1, ll, rr, f);
    }

    int find_last(int ll, int rr, const function<bool(const Node&)> &f) {
        assert(ll >= 0 && ll <= rr && rr < n);
        return find_last(1, 0, n - 1, ll, rr, f);
    }
};

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SegmentTree seg(a);
    int i = 0, j = n - 1;
    int orr = 0;
    vector<int> ans(n);
    for (int k = n - 2; k >= 0; k--) {
        orr |= a[i++];
        orr |= a[j--];
        int res = orr;
        if (i <= j) {
            res &= seg.get(i, j).sum;
        }
        ans[k] = res;
    }
    ans[n - 1] = ans[n - 2];

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
