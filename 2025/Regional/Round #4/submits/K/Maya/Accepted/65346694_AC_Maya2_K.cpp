#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
using ll = long long;
using ld = long double;
//#define TESTCASE
//#define TIME
#ifdef DEBUG
#include "/home/pouya/dev/cp/lib/debug.cpp"
#else
#define dbg(...)
#define Solve solve
#endif
#define nl endl;cout.flush();

void solve(int tc) {
    vector<array<int, 2>> ord = {
        {2, 2},
        {4, 4},
        {4, 2},
        {2, 4}
    };
    auto qry = [&] (int x, int y) {
        cout << "? "<< x << ' ' << y << nl;
        int res; cin >> res;
        return res;
    };
    auto say = [&] (int x, int y) {
        cout << "! "<< x << ' ' << y << nl;
    };
    for (int k=0; k<4; k++) {
        int x = ord[k][0], y = ord[k][1];
        int res;
        if (k < 3) {
            res = qry(x, y);
        }
        if (res || k == 3) {
            dbg(x, y);
            int dx = 3-x, dy = 3-y;
            int res1 = qry(x+dx, y), res2 = qry(x, y+dy);
            vector<array<int, 2>> sq;
            dbg(res1, res2);
            if (!res1) {
                dx *= -1;
            }
            if (!res2) {
                dy *= -1;
            }
            dbg(dx, dy);
            for (int i: {0, 1}) {
                for (int j: {0, 1}) {
                    sq.push_back({x+i*dx, y+j*dy});
                }
            }
            sort(sq.begin(), sq.end());
            auto [xx, yy] = *sq.begin();

            say(xx, yy);
            return;
        }
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    
    #ifdef TESTCASE
    cin >> t;
    #endif
    for (int i=1; i<=t; i++) {
        Solve(i);
    }
    return 0;
}
