#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAXN = 500005;

struct SegmentTree {
    vector<int> tree;
    int size;

    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n);
    }

    void build(const vector<int>& data, int node, int l, int r) {
        if (l == r) {
            tree[node] = data[l];
        } else {
            int mid = (l + r) / 2;
            build(data, 2 * node, l, mid);
            build(data, 2 * node + 1, mid + 1, r);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int l, int r, int pos, int value) {
        if (l == r) {
            tree[node] = value;
        } else {
            int mid = (l + r) / 2;
            if (pos <= mid) update(2 * node, l, mid, pos, value);
            else update(2 * node + 1, mid + 1, r, pos, value);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) +
               query(2 * node + 1, mid + 1, r, ql, qr);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        string instr;
        cin >> instr;
        instr = " " + instr;  // 1-based indexing

        vector<int> vertical(m + 1), horizontal(m + 1);

        for (int i = 1; i <= m; ++i) {
            if (instr[i] == 'U') vertical[i] = -1;
            else if (instr[i] == 'D') vertical[i] = 1;
            else vertical[i] = 0;

            if (instr[i] == 'L') horizontal[i] = -1;
            else if (instr[i] == 'R') horizontal[i] = 1;
            else horizontal[i] = 0;
        }

        SegmentTree segVert(m), segHoriz(m);
        segVert.build(vertical, 1, 1, m);
        segHoriz.build(horizontal, 1, 1, m);

        while (k--) {
            int op;
            cin >> op;
            if (op == 1) {
                int x, y, l, r;
                cin >> x >> y >> l >> r;
                int dy = segVert.query(1, 1, m, l, r);
                int dx = segHoriz.query(1, 1, m, l, r);
                x += dy;
                y += dx;
                x = max(1, min(n, x));
                y = max(1, min(n, y));
                cout << x << " " << y << '\n';
            } else if (op == 2) {
                int pos;
                char c;
                cin >> pos >> c;
                int vert = 0, horiz = 0;
                if (c == 'U') vert = -1;
                else if (c == 'D') vert = 1;
                else if (c == 'L') horiz = -1;
                else if (c == 'R') horiz = 1;
                segVert.update(1, 1, m, pos, vert);
                segHoriz.update(1, 1, m, pos, horiz);
            }
        }
    }

    return 0;
}
