#ifdef LOCAL
#define _GLIBCXX_DEBUG
#define nl endl
#else
#define nl '\n'
#endif

#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
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
#define dbg(v) \
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

const int mxn = 3e5 + 4;

void solve()
{
    int n;
    cin >> n;

    set<string> p;
    int x = 0, y = 0, valid = -1, end = 0;
    for (int i = 0; i < n; i++)
    {
        str s;
        cin >> s;

        if (valid != -1)
            continue;

        if (p.find(s) != p.end())
            continue;
        p.insert(s);

        int a = stoi(s.substr(0, s.find('-') + 1));
        int b = stoi(s.substr(s.find('-') + 1));

        int round = (a + b + 1) / 2;
        if (round % 2 == 1)
            swap(a, b);

        if (a > 11 or b > 11)
            valid = i;
        if (a == 11 and b == 11)
            valid = i;
        if (end == 1)
            valid = i;
        if (a < x or b < y)
            valid = i;

        x = a, y = b;
        if (max(x, y) == 11)
            end = 1;
    }

    cout << ((valid == -1) ? "ok" : "error " + to_string(valid + 1)) << endl;
}

int32_t main()
{
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#else
    fastio
#endif

    int t = 1;
    while (t--)
        solve();

    return 0;
}
