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
set<int> childs[maxn];

void zero_cost(int i) 
{
    cost[i] = 0;
    for (int x: v[i]) {
        zero_cost(x);
    }
}

void child(int i, int x) 
{
    childs[i].insert(x);
    for (int y: v[x]) {
        child(i, y);
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

    for (int i = 0; i < n; i++) {
        for (int x: v[i]) {
            child(i, x);
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
                    break;
                }
            }
            
            if (ff) {
                // cout << i << ' ' << cost0 << '\n';
                for (int x: childs[i]) {
                    cost0 += cost[x];
                }
                done[i] = 1;
                f = true;
                if (cost0 >= 0) {
                    ans += cost0;
                    zero_cost(i);
                }
                // else {
                //     cost[i] = cost0;
                // }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}