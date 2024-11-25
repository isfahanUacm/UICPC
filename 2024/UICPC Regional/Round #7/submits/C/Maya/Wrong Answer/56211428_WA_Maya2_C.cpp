#include <bits/stdc++.h>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "/home/babilash/blue-folder/cp/cf/debug.h"
#else
#define dbg(...)
#define dbgarr(...)
#endif

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        mp[tmp]++;
    }

    bool mn1=0, mn2=0, mx1=0, mx2=0;
    int min1, min2, max1, max2;
    for (auto &pr : mp) {
        if (pr.second >= 2) {
            if (!mn1) {
                min1 = pr.first;
                pr.second -= 2;
                mn1 = 1;
            } else if (!mn2) {
                min2 = pr.first;
                pr.second -= 2;
                mn2 = 1;
                break;
            }
        }
    }
    dbg(mp);
    for (auto it = mp.rbegin(); 1; ++it) {
        if (it->second >= 2) {
            if (!mx1) {
                max1 = it->first;
                it->second -= 2;
                mx1 = 1;
            } else if (!mx2) {
                max2 = it->first;
                it->second -= 2;
                mx2 = 1;
                break;
            }
        }
        if (it == mp.rend()) break;
    }
    dbg(mp);

    if (mn1 and mn2 and mx1 and mx2) {
        cout << "YES" << endl;
        cout << min1 << ' ' << min2 << ' ';
        cout << max2 << ' ' << min2 << ' ';
        cout << min1 << ' ' << max1 << ' ';
        cout << max2 << ' ' << max1 << endl;
    } else {
        cout << "NO" << endl;
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