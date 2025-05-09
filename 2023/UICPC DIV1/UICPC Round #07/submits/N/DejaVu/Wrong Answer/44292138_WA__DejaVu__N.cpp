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

int main()
{
    fastio;

    int n, m;
    cin >> n >> m;

    string res = ";;;;;";
    unordered_map<char, unordered_set<int>> Y;
    unordered_set<char> N;

    for (int i = 0; i < n; i++)
    {
        string p, q;
        cin >> p >> q;
        unordered_set<char> Gt;
        unordered_map<char, unordered_set<int>> Yt;
        unordered_set<char> Nt, YV;

        for (int i = 0; i < 5; i++)
        {
            if (q[i] == 'G')
            {
                Gt.insert(p[i]);
            }
        }

        for (int i = 0; i < 5; i++)
        {
            if (q[i] == 'G')
            {
                res[i] = p[i];
                Gt.insert(p[i]);
            }
            else if (q[i] == 'Y')
            {
                Y[p[i]].insert(i);
                YV.insert(p[i]);
            }
            else if (q[i] == '-' && YV.find(p[i]) == YV.end() && Gt.find(p[i]) == Gt.end())
                Nt.insert(p[i]);
        }

        for (auto t : Nt)
            N.insert(t);
        }

    for (int i = 0; i < m; i++)
    {
        string p;
        cin >> p;

        bool fg = true;

        for (int i = 0; i < 5; i++)
        {
            if (res[i] != ';' && res[i] != p[i])
            {
                fg = false;
                break;
            }
        }

        for (auto c : Y)
        {
            int idx = p.find(c.first);
            if (idx == -1 || c.second.find(idx) != c.second.end())
            {
                fg = false;
                break;
            }
        }

        for (char c : N)
        {
            if (p.find(c) != -1)
            {
                fg = false;
                break;
            }
        }

        if (fg)
            cout << p << '\n';
    }
    return 0;
}

