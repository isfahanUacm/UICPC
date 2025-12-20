#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

// Count Inversions, O(n*log(n))
template <typename T, typename Compare>
int64_t merge(vector<T>& a, int l, int r, int m, Compare cmp) {
    vector<T> left(a.begin() + l, a.begin() + m + 1);
    vector<T> right(a.begin() + m + 1, a.begin() + r + 1);
    int n1 = left.size(), n2 = right.size();

    int64_t inv = 0;
    int i = 0, j = 0, k = l;
    while (i < n1 || j < n2) {
        if (i < n1 && (j >= n2 || cmp(left[i], right[j]))) {
            a[k++] = left[i++];
            inv += j;
        } else {
            a[k++] = right[j++];
        }
    }
    return inv;
}

template <typename T, typename Compare>
int64_t inversion(vector<T>& a, int l, int r, Compare cmp) {
    if (l >= r) {
        return 0;
    }
    int64_t inv = 0;
    int m = l + (r - l) / 2;
    inv += inversion(a, l, m, cmp);
    inv += inversion(a, m + 1, r, cmp);
    inv += merge(a, l, r, m, cmp);
    return inv;
}

template <typename T, typename Compare = less<T>>
int64_t inversion(vector<T> a, Compare cmp = Compare()) {
    return inversion(a, 0, a.size() - 1, cmp);
}

void solve() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            return;
        }

        vector<int> a(2 * n), cnt(n), b;
        b.reserve(2 * n);
        vector<bool> vis(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
            a[i]--;
            cnt[a[i]]++;
        }

        int64_t ans = 0, num = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (cnt[a[i]]) {
                b.push_back(a[i]);
                cnt[a[i]] -= 2;
                vis[i] = true;
                ans += num;
            } else {
                num++;
            }
        }
        for (int i = 0; i < 2 * n; i++) {
            if (!vis[i]) {
                b.push_back(a[i]);
            }
        }
        
        vector<vector<int>> w(n);
        for (int i = 2 * n - 1; i >= n; i--) {
            w[b[i]].push_back(i); 
        }
        for (int i = 0; i < n; i++) {
            b[w[b[i]].back()] = i;
            w[b[i]].pop_back();
        }

        b.erase(b.begin(), b.begin() + n);
        ans += inversion(b);

        cout << ans << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
