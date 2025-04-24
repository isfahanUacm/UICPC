#include <bits/stdc++.h>
using namespace std;

const int B = 440;
struct Query {
    int l, r, k, id;
    bool operator<(const Query &other) const {
        if (l / B == other.l / B) {
            return ((l / B) & 1) ? r > other.r : r < other.r;
        }
        return l / B < other.l / B;
    }
};

vector<int> spf, primes;
void sieve(int n) {
    spf.assign(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < (int)primes.size() && i * primes[j] <= n && primes[j] <= spf[i]; j++) {
            spf[i * primes[j]] = primes[j];
        }
    }
}

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

    int q;
    cin >> q;

    vector<Query> qr(q);
    for (int i = 0; i < q; i++) {
        cin >> qr[i].l >> qr[i].r >> qr[i].k;
        qr[i].l--, qr[i].r--;
        qr[i].id = i;
    }
    sort(qr.begin(), qr.end());

    const int N = 1e6 + 10;
    vector<int> cnt(N + 1);
    auto add = [&](int i) -> void {
        int x = a[i];
        while (spf[x] != x) {
            cnt[spf[x]]++;
            x = x / spf[x];
        }
        cnt[x]++;
    };
    auto rem = [&](int i) -> void {
        int x = a[i];
        while (spf[x] != x) {
            cnt[spf[x]]--;
            x = x / spf[x];
        }
        cnt[x]--;
    };
    auto query = [&](int k) -> bool {
        int num = 1, prv = spf[k];
        while (spf[k] != k) {
            k = k / spf[k];
            if (spf[k] == prv) {
                num++;
            }
            else {
                if (cnt[prv] < num) {
                    return false;
                }
                num = 1;
                prv = spf[k];
            }
        }
        if (cnt[prv] < num) {
            return false;
        }
        return true;
    };

    vector<char> ans(q);
    int l = 1, r = 0;
    for (int i = 0; i < q; i++) {
        int L = qr[i].l, R = qr[i].r;
        while (l < L) rem(l++);
        while (l > L) add(--l);
        while (r < R) add(++r);
        while (r > R) rem(r--);
        ans[qr[i].id] = query(qr[i].k);
    }

    for (int i = 0; i < q; i++) {
        cout << (ans[i] ? "Yes\n" : "No\n");
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 1e6 + 10;
    sieve(N);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
