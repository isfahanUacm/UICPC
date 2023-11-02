// l a s h v

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define endll '\n'
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fori(x, u) for (int i = x; i < u; ++i)
#define forj(x, u) for (int j = x; j < u; ++j)
#define sortv(a) sort(a.begin(), a.end())
#define ES cout << "YES\n"
#define NO cout << "NO\n"
#define sep() cout << "------------------------------------------------------\n"
#define print_map(mp) for (auto x : mp) cout << x.first << ": " << x.second << endll
#define print_vec(vc) for (auto x : vc) cout << x << ' '; cout << endll
// lower_bound -> greater than or equal
// upper_bound -> greater than
const int maxn = 2e5+9;

void solve() {
    int x, y;
    cin >> x >> y;
    if (x == y) {
        cout << y << endll;
        return;
    }
    x--; y--;
    if (x > y) swap (x, y);
    ll time = 1;
    int row = 0, col = y, dir = 1;
    int tag, bug;
    tag = y / x; bug = y % x;
    if (tag % 2 != 0) dir = 2;
    if (dir == 1) row = bug;
    else row = x - bug;
    if (dir == 1) dir = 3;
    else dir = 4;
    if (bug == 0) {
        cout << y+1 << endll;
        return;
    }
    while (true) {
        time++;
        int step = y;
        if (dir == 1 || dir == 2) {  // to right
            if (dir == 1) {
                step -= (x-row);
            }
            else {
                step -= row;
            }
            tag = step / x;
            bug = step % x;
            if (tag % 2 != 0) {
                if (dir == 1) dir = 2;
                else dir = 1;
            }
            if (dir == 1) row = bug;
            else row = x - bug;

            if (dir == 1) dir = 3;
            else dir = 4;
        }
        else { // to left
            if (dir == 3) step -= (x-row);
            else step -= row;
            tag = step / x;
            bug = step % x;
            if (tag % 2 != 0) {
                if (dir == 3) dir = 4;
                else dir = 3;
            }
            if (dir == 3) row = bug;
            else row = x - bug;

            if (dir == 3) dir = 1;
            else dir = 2;
        }
        if (row == 0 || row == x) break;
    }
    int jeez = ceil (y*1.0/x*1.0);
    cout << (time * (y+1)) - (time * (time -1)) * jeez / 2 << endll;
}

int main() {
    ios::sync_with_stdio(false);
		cin.tie(nullptr);
    //cout << fixed << setprecision(9);
    int T; cin >> T; while (T--)
    solve();

    return 0;
}