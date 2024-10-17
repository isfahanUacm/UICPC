#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using str = string;

template <class T>
using pqg = priority_queue<T>;
template <class T>
using pql = priority_queue<T, vector<T>, greater<T>>;

const ll inf = 1e18;
const ll MOD = 1e9 + 7;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T>
bool cmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <typename T>
bool cmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

ll modOp(ll a, ll b, int op)
{
    switch (op)
    {
    case 0:
        return ((a % MOD) + (b % MOD)) % MOD;
    case 1:
        return ((a % MOD) - (b % MOD) + MOD) % MOD;
    case 2:
        return (a % MOD) * (b % MOD) % MOD;
    }
    return 0;
}

#ifdef LOCAL
#define _GLIBCXX_DEBUG
#define nl endl
#else
#define nl '\n'
#endif

const int N = 2e5 + 1;
vl p(3), q(3), l(3), r(3);
vector<vl> ans(14000, vl(3));
int cnt = 0;

void solve()
{
    for (int i = 0; i < 3; i++)
        cin >> p[i];
    for (int i = 0; i < 3; i++)
        cin >> q[i];

    for (int i = 0; i < 3; i++)
        cin >> l[i];
    for (int i = 0; i < 3; i++)
        cin >> r[i];

    ans[cnt++] = p;
    ans[cnt++] = l;

    if (p[2] == l[2])
    {
        p[2]++;
        ans[cnt++] = p;

        ans[cnt++] = l;
    }

    while (p[0] != q[0] or p[1] != q[1] or l[0] != r[0] or l[1] != r[1])
    {
        if (p[0] == q[0] and p[1] == q[1])
        {
            ans[cnt++] = p;

            if (l[0] > r[0])
                l[0]--, ans[cnt++] = l;
            else if (l[0] < r[0])
                l[0]++, ans[cnt++] = l;
            else if (l[1] > r[1])
                l[1]--, ans[cnt++] = l;
            else if (l[1] < r[1])
                l[1]++, ans[cnt++] = l;
        }
        else if (l[0] == r[0] and l[1] == r[1])
        {
            if (p[0] > q[0])
                p[0]--, ans[cnt++] = p;
            else if (p[0] < q[0])
                p[0]++, ans[cnt++] = p;
            else if (p[1] > q[1])
                p[1]--, ans[cnt++] = p;
            else if (p[1] < q[1])
                p[1]++, ans[cnt++] = p;

            ans[cnt++] = l;
        }
        else
        {

            if (p[0] > q[0])
                p[0]--, ans[cnt++] = p;
            else if (p[0] < q[0])
                p[0]++, ans[cnt++] = p;
            else if (p[1] > q[1])
                p[1]--, ans[cnt++] = p;
            else if (p[1] < q[1])
                p[1]++, ans[cnt++] = p;

            if (l[0] > r[0])
                l[0]--, ans[cnt++] = l;
            else if (l[0] < r[0])
                l[0]++, ans[cnt++] = l;
            else if (l[1] > r[1])
                l[1]--, ans[cnt++] = l;
            else if (l[1] < r[1])
                l[1]++, ans[cnt++] = l;
        }
    }

    if (q[0] != r[0] or q[1] != r[1])
    {
        while (p[2] != q[2] or l[2] != r[2])
        {
            if (p[2] == q[2])
            {
                ans[cnt++] = p;

                if (l[2] > r[2])
                    l[2]--, ans[cnt++] = l;
                else
                    l[2]++, ans[cnt++] = l;
            }
            else if (l[2] == r[2])
            {
                if (p[2] > q[2])
                    p[2]--, ans[cnt++] = p;
                else
                    p[2]++, ans[cnt++] = p;

                ans[cnt++] = l;
            }
            else
            {
                if (p[2] > q[2])
                    p[2]--, ans[cnt++] = p;
                else
                    p[2]++, ans[cnt++] = p;

                if (l[2] > r[2])
                    l[2]--, ans[cnt++] = l;
                else
                    l[2]++, ans[cnt++] = l;
            }
        }
    }
    else
    {
        l[0]++;
        ans[cnt++] = p, ans[cnt++] = l;

        while (p[2] != q[2] or l[2] != r[2])
        {
            if (p[2] == q[2])
            {
                ans[cnt++] = p;

                if (l[2] > r[2])
                    l[2]--, ans[cnt++] = l;
                else
                    l[2]++, ans[cnt++] = l;
            }
            else if (l[2] == r[2])
            {
                if (p[2] > q[2])
                    p[2]--, ans[cnt++] = p;
                else
                    p[2]++, ans[cnt++] = p;

                ans[cnt++] = l;
            }
            else
            {
                if (p[2] > q[2])
                    p[2]--, ans[cnt++] = p;
                else
                    p[2]++, ans[cnt++] = p;

                if (l[2] > r[2])
                    l[2]--, ans[cnt++] = l;
                else
                    l[2]++, ans[cnt++] = l;
            }
        }

        l[0]--;
        ans[cnt++] = p, ans[cnt++] = l;
    }

    for (int i = 0; i < cnt; i += 2)
    {
        cout << "(" << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << ") ";
        cout << "(" << ans[i + 1][0] << " " << ans[i + 1][1] << " " << ans[i + 1][2] << ") " << endl;
    }
}

int32_t main()
{
    fastio;

    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    return 0;
}