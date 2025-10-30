#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    int n;
    cin >> n;
    vector<pair<string , double>> a(n);
    string temp;
    vi live(n , 0);
    ld sum = 0.0;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        getline(cin >> ws , temp);
        string t1;
        stringstream  ss(temp);
        ss >> t1;
        a[i].first = t1;
        double num;
        if(ss >> num){
            a[i].second = num;
            sum += a[i].second;
            flag = true;
        }
        else{
            a[i].second = -1;
            live[i] = 1;
        }
    }
    double mn = 0.0;
    vector<pair<double, double>> ans(n , {0 , 0});
    if(flag) {
        for (int i = n - 1; i >= 0; --i) {
            if (live[i]) {
                ans[i].first = mn;
            }
            else {
                mn = a[i].second;
            }
        }
        vector<double> pre(n , 0.0);
        pre[0] = ans[0].first;
        for (int i = 1; i < n; ++i) {
            if (live[i])
                pre[i] = pre[i - 1] + ans[i].first;
            else {
                pre[i] = pre[i - 1];
            }
        }
        vector<double> pre2(n , 0.0);
        pre2[n - 1] = ans[n - 1].first;
        for (int i = n - 2; i >= 0; --i) {
            if (live[i])
                pre2[i] = pre2[i + 1] + ans[i].first;
            else {
                pre2[i] = pre2[i + 1];
            }
        }
        int l = 0 , r = 0;
        while(r < n){
            if(!live[r]){
                double cnt = 100 - (pre[l] + pre2[l] + sum - ans[l].first);
                int m = 1;
                for (int i = l; i < r; ++i) {
                    ans[i].second = ans[i].first + (cnt / m);
                    m++;
                }
                l = r + 1;
                r++;
            }
            r++;
        }
        if(live[n - 1]){
            double cnt = 100 - (pre[l] + pre2[l] + sum - ans[l].first);
            double m = 1;
            for (int i = l; i < n; ++i) {
                ans[i].second = ans[i].first + (cnt / m);
                m++;
            }
        }
         int cnt = count(live.begin(), live.end() , 1);
        if(cnt == 1){
            for (int i = 0; i < n; ++i) {
                if(live[i]){
                    ans[i].first = ans[i].second;
                }
            }
        }
    }
    else{
        ans[0].first = double(100.0 / (double)n);
        for (int i = 0; i < n; ++i) {
            ans[i].second = double(100.0 / double(i + 1));
        }
    }
    for (int i = 0; i < n; ++i) {
        if(live[i]){
            cout << a[i].first << " ";
            cout << fixed << setprecision(10) << ans[i].first << " " << ans[i].second << "\n";
        }
    }
    cout << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    while (T--)
        solve();
    return 0;
}