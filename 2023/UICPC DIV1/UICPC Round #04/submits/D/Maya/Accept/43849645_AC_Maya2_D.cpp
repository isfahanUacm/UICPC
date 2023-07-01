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
#define inf 1e9

const int maxn = 2e3 + 10;
int mn[maxn];
int mx[maxn];

ld dis(int x1, int y1, int x2, int y2) 
{
    x1 -= 1000;
    x2 -= 1000;

    ld ans = sqrt(pow(1ll * x1 - 1ll * x2, 2) + pow(1ll * y1 - 1ll * y2, 2));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    fill(mn, mn + maxn, inf);
    fill(mx, mx + maxn, -inf);

    while (n--) {
        int x, y;
        cin >> x >> y;
        x += 1000;
        mn[x] = min(mn[x], y);
        mx[x] = max(mx[x], y);
    }

    ld mxx = 0;
    for (int i = 0; i < maxn; i++) {
        for (int j = i + 1; j < maxn; j++) {
            if (mn[i] != inf && mx[j] != -inf)
                mxx = max(mxx, dis(i, mn[i], j, mx[j]));
            if (mx[i] != -inf && mn[j] != inf)
                mxx = max(mxx, dis(i, mx[i], j, mn[j]));
        }
    }
    cout << fixed << setprecision(8);
    cout << mxx << '\n';

    return 0;
}