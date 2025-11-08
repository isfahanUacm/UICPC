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

    multiset<pair<double, array<int, 2>>> pq; // weight / num, num, index
    multiset<pair<array<int, 2>, double>> ms; // index, num, weight / num
    for (int i = 0; i < n; i++) {
        pair<double, array<int, 2>> x = {double(a[i][1]), {1, i}};
        pair<array<int, 2>, double> y = {{i, 1}, double(a[i][1])};
        pq.insert(x);
        ms.insert(y);
    }

    double ans = 0;
    while (diff) {
        auto [weight, arr] = *pq.rbegin();
        auto [num, ind] = arr;
        pair<array<int, 2>, double> tmp = {{ind, num}, weight};
        weight *= num;
        dbg(pq);
        dbg(ms);
        pq.erase(--pq.end());
        
        int64_t curr = a[ind][0];


        dbg(ms);
        if (right > left) {
            auto pointer_prv = ms.find(tmp);
            int64_t prev = -4e18;
            int num_tmp, ind_tmp;
            double w_tmp;
            if (pointer_prv != ms.begin()) {
                pointer_prv--;
                prev = a[(*pointer_prv).first[0]][0];
                ms.erase(pointer_prv);
                auto [arr_tmp, w_tmp2] = *pointer_prv;
                auto [ind_tmp2, num_tmp2] = arr_tmp;
                num_tmp = num_tmp2, ind_tmp = ind_tmp2;
                w_tmp = w_tmp2;
                pair<double, array<int, 2>> y_tmp = {w_tmp, {num_tmp, ind_tmp}};
                pq.erase(pq.find(y_tmp));
            }
            w_tmp *= num_tmp;
            ms.erase(ms.find(tmp));
            int64_t dis = curr - prev;
            dbg(weight, num, diff, curr, prev);
            if (dis * weight < diff) {
                ans += dis * num;
                diff -= dis * weight;
                pair<double, array<int, 2>> x = {(weight + w_tmp) / (num + num_tmp), {num + num_tmp, ind_tmp}};
                pair<array<int, 2>, double> y = {{ind_tmp, num + num_tmp}, (weight + w_tmp) / (num + num_tmp)};
                pq.insert(x);
                ms.insert(y);
            } else {
                double d = double(diff) / weight; 
                ans += d * num;
                diff = 0;
            }
        } else {
            auto pointer_nxt = ++ms.find(tmp);
            int64_t next = 4e18;
            int ind_tmp, num_tmp;
            double w_tmp;
            if (pointer_nxt != ms.end()) {
                next = a[(*pointer_nxt).first[0]][0];
                ms.erase(pointer_nxt);
                auto [arr_tmp, w_tmp2] = *pointer_nxt;
                auto [ind_tmp2, num_tmp2] = arr_tmp;
                num_tmp = num_tmp2, ind_tmp = ind_tmp2;
                w_tmp = w_tmp2;
                pair<double, array<int, 2>> y_tmp = {w_tmp, {num_tmp, ind_tmp}};
                pq.erase(pq.find(y_tmp));
            }
            w_tmp *= num_tmp;
            ms.erase(ms.find(tmp));
            int64_t dis = next - curr;
            dbg(weight, num, diff, curr, next);
            if (dis * weight < diff) {
                ans += dis * num;
                diff -= dis * weight;
                pair<double, array<int, 2>> x = {(weight + w_tmp) / (num + num_tmp), {num + num_tmp, ind_tmp}};
                pair<array<int, 2>, double> y = {{ind_tmp, num + num_tmp}, (weight + w_tmp) / (num + num_tmp)};
                pq.insert(x);
                ms.insert(y);
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
