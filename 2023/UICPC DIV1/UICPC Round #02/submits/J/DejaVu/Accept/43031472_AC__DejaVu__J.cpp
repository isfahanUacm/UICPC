#include <bits/stdc++.h>
using namespace std;

typedef string str;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll mod = 1e9 + 7;

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

ll mul(ll a, ll b)
{
    return (a % mod) * (b % mod) % mod;
}

ll min(ll a, ll b)
{
    return ((a % mod) - (b % mod) + mod) % mod;
}

ll sum(ll a, ll b)
{
    return ((a % mod) + (b % mod)) % mod;
}

int main()
{
    fastio;
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cin.ignore();

        vector<vector<int>> a;
        bool fi = true;
        for (int i = 0; i < m; i++)
        {
            string s;
            getline(cin, s);

            string delimiter = " v ";
            size_t pos_start = 0, pos_end, delim_len = delimiter.length();
            string token;
            vector<int> res;

            while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
            {
                token = s.substr(pos_start + 1, pos_end - pos_start - 1);
                if (token[0] == 'X')
                    token[0] = '-';
                pos_start = pos_end + delim_len;
                res.push_back(stoi(token));
            }
            token = s.substr(pos_start + 1, s.length());
            if (token[0] == 'X')
                token[0] = '-';
            res.push_back(stoi(token));
            a.push_back(res);
        }

        bool flag2 = false;
        for (int j = 0; j < 1 << n; j++)
        {
            bool flag = true;
            for (vector<int> u : a)
            {
                bool fg = false;
                for (int v : u)
                {
                    int period = pow(2, abs(v) - 1);
                    bool value = (j / period) % 2;
                    if (v < 0)
                        if(value) value = false;
                        else value = true;

                    if (value)
                    {
                        fg = true;
                        break;
                    }
                }

                if(!fg)
                {
                    flag = false;
                    break;
                }
            }

            if(flag)
            {
                flag2 = true;
                break;
            }
        }

        if(flag2) cout << "satisfiable";
        else cout << "unsatisfiable";

        cout << '\n';
    }

    return 0;
}
