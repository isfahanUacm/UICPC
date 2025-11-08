#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n;
    cin >> n;

    vector<array<int64_t, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    int64_t left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][0] < 0) {
            left += abs(a[i][0]) * a[i][1];
        } else {
            right += a[i][0] * a[i][1];
        }
    }
    int64_t diff = abs(left - right);
    dbg(left, right);

    priority_queue<pair<double, array<int, 2>>> pq; // weight / num, num, index
    for (int i = 0; i < n; i++) {
        pair<double, array<int, 2>> x = {double(a[i][1]), {1, i}};
        pq.push(x);
    }

    double ans = 0;
    while (diff) {
        auto [weight, arr] = pq.top();
        auto [num, ind] = arr;
        weight *= num;
        pq.pop();
        
        int64_t curr = a[ind][0];
        int64_t next = ind == n - 1 ? 2e18 : a[ind + 1][0];
        int64_t prev = ind == 0 ? -2e18 : a[ind - 1][0];

        dbg(weight, num, diff, curr, next, prev);

        if (right > left) {
            int64_t dis = curr - prev;
            if (dis * weight < diff) {
                ans += dis * num;
                diff -= dis * weight;
                pair<double, array<int, 2>> x = {(weight + double(a[ind - 1][1])) / (num + 1), {num + 1, ind - 1}};
                pq.push(x);
            } else {
                double d = double(diff) / weight; 
                ans += d * num;
                diff = 0;
            }
        } else {
            int64_t dis = next - curr;
            if (dis * weight < diff) {
                ans += dis * num;
                diff -= dis * weight;
                pair<double, array<int, 2>> x = {(weight + double(a[ind + 1][1])) / (num + 1), {num + 1, ind + 1}};
                pq.push(x);
            } else {
                double d = double(diff) / weight; 
                ans += d * num;
                diff = 0;
            }
        }
    }
    cout << fixed << setprecision(6) << ans << '\n';
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
