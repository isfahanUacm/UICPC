#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define F first
#define S second
#define vi vector<int>
#define pb push_back
#define pf push_front

const int maxn = 2e3 + 10;
int cost[maxn];
int done[maxn];
vi v[maxn];

void zero_cost(int i) 
{
    cost[i] = 0;
    for (int x: v[i]) {
        zero_cost(x);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        cost[i] = b - a;
        for (int j = 0; j < t; j++) {
            int x;
            cin >> x;
            x--;
            v[i].pb(x);
        }
    }

    ll ans = 0;
    bool f = true;
    while (f) {
        f = false;
        for (int i = 0; i < n; i++) {
            // cout << i << ' ' << cost[i] << '\n';
            if (done[i]) continue;
            ll cost0 = cost[i];
            
            bool ff = true;
            for (int x: v[i]) {
                if (done[x] == 0) {
                    ff = false;
                }
                cost0 += cost[x];
            }
            if (ff) {
                // cout << i << ' ' << cost0 << '\n';
                done[i] = 1;
                f = true;
                if (cost0 < 0) {
                    cost[i] = cost0;
                }
                else {
                    ans += cost0;
                    zero_cost(i);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
