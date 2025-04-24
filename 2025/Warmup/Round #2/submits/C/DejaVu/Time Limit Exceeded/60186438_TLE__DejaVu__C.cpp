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

const int N = 2e5 + 1;

ll cal(str p) {
    stack<char> st;
    ll ans = 0;

    for (char c : p) {
        if (c == '(') {
            st.push(c);
        }
        else {
            st.pop();
            ans++;
        }
    }

    return ans;
}

str crt(ll v) {
    str ans;
    for (int i = 0; i < v; i++) {
        ans.pb('(');
    }
    for (int i = 0; i < v; i++) {
        ans.pb(')');
    }
    return ans;
}

bool cor(str s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(') {
            st.push(c);
        }
        else {
            if (st.empty()) {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

ll find(str s) {
    for (int i = 0; i < sz(s); i++) {
        if (s[i - 1] == ')' and s[i] == '(') {
            return i;
        }
    }
    return -1;
}

void solve() {
    ll n;
    cin >> n;

    str s;
    cin >> s;

    int idx;
    while ((idx = find(s)) > -1) {
        ll a, b;

        str t1;
        ll j = idx;
        while (j < n) {
            t1.pb(s[j++]);
            if (cor(t1)) {
                a = cal(t1);
                break;
            }
        }

        str t2;
        ll z = idx - 1;
        while (z >= 0) {
            t2.pb(s[z--]);
            reverse(all(t2));
            if (cor(t2)) {
                b = cal(t2);
                break;
            }
            reverse(all(t2));
        }

        s = s.substr(0, z + 1) + crt(a * b) + s.substr(j, n - j);
    }

    cout << cal(s) << endl;
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
