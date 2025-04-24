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

template <class T> using pqg = priority_queue<T>;
template <class T> using pql = priority_queue<T, vector<T>, greater<T>>;

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

template <typename T> bool cmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <typename T> bool cmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef LOCAL
#define _GLIBCXX_DEBUG
#define nl endl
#else
#define nl '\n'
#endif

const int N = 100 + 1;

void solve() {
    ll n;
    cin >> n;

    str s;
    cin >> s;

    stack<char> st;
    stack<pl> nm;

    for (char c : s) {
        if (c == '(') {
            st.push(c);
            nm.push({0, 0});
        }
        else {
            bool flag = true;
            ll v = 1;
            while (!nm.empty() and nm.top().S != 0) {
                v *= nm.top().F;
                nm.pop();
                flag = false;
            }
            nm.pop();

            if (flag) {
                nm.push({v, 1});
            }
            else {
                nm.push({v + 1, 1});
            }
        }
    }

    cout << nm.top().F << endl;
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
