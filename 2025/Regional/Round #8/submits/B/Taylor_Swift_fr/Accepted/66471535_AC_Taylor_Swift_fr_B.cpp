#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define F first
#define S second
#define pii pair<int, int>
#define piii pair<char, int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back
#define pf push_front
#define ins insert
#define pbd pop_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define wall cout << '\n' \
                  << "--------------------------------" << '\n';
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define filin                          \
    freopen("problem.in", "r", stdin); \
    freopen("problem.out", "w", stdout);

const int N = 2e5 + 9, MOD = 1e9 + 7, SQ = 548, LG = 20, INF = LLONG_MAX;

ll pw(ll a, ll b) { return b == 0 ? 1LL : (pw(a * a, b / 2) * (b % 2 == 0 ? 1LL : a)); }
ll pwm(ll a, ll b) { return b == 0 ? 1LL : (pw(a * a % MOD, b / 2) % MOD * (b % 2 == 0 ? 1LL : a)) % MOD; }

vector<int> computeLPSArray(string &pattern)
{
    int n = pattern.size();
    vector<int> lps(n, 0);

    // length of the previous longest prefix suffix
    int len = 0;
    int i = 1;

    while (i < n)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                // fall back in the pattern
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int32_t main()
{
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            return 0;
        }
        string s, t, ans;
        cin >> s;
        auto v = computeLPSArray(s);
        /*for (int i = 0; i < v.size(); i++)
            cout << v[i] << ' ';
        cout << endl;*/
        ans += s;
        for (int i = v[n - 1]; i < n; i++)
            ans += s[i];
        cout << ans << endl;
    }
}