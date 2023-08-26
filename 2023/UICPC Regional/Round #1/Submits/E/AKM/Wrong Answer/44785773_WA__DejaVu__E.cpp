#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll MOD = 1e9 + 7;
#define nl "\n"
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
#define dbg(v) \
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

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
}

std::vector<std::string> split(std::string s, std::string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

void solve()
{
    string s;
    cin >> s;

    string u = "";
    for (int i = 0; i < sz(s); i++)
    {
        if (s[i] == '*')
        {
            int j = i + 1;
            while (j < sz(s) && s[j] == '*')
            {
                j++;
            }
            i = j - 1;
            u.push_back('*');
        }
        else
            u.push_back(s[i]);
    }

    int t;
    cin >> t;
    s = u;

    while (t--)
    {
        u = s;
        string p;
        cin >> p;
        string aim = p;

        bool valid = true;

        int l = 0;
        while (l < sz(u) && l < sz(p) && u[l] != '*' && u[l] == p[l])
        {
            l++;
        }
        if (l < sz(u) && l < sz(p) && u[l] != '*' && u[l] != p[l])
        {
            continue;
        }

        p = p.substr(l);
        u = u.substr(l);

        int r1 = sz(u) - 1, r2 = sz(p) - 1;
        while (r1 >= 0 && r2 >= 0 && u[r1] != '*' && u[r1] == p[r2])
        {
            r1--;
            r2--;
        }
        if (r1 >= 0 && r2 >= 0 && u[r1] != '*' && u[r1] != p[r2])
        {
            continue;
        }

        p = p.substr(0, r2 + 1);
        u = u.substr(0, r1 + 1);
        
        if (sz(u) == 0)
        {
            if (sz(p) == 0)
                break;
        }
        else if (sz(u) == 1)
        {
            cout << aim << nl;
        }
        else
        {
            u = u.substr(1);
            u.pop_back();

            vector<string> res = split(u, "*");
            int cnt = 0;
            for (string v : res)
            {
                if (p.find(v) != -1)
                {
                    cnt = p.find(v) + 1;
                }
                else
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
                cout << aim << nl;
        }
    }
}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
