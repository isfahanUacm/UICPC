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

int n;
int s = 0;
vector<int> a;

void solve(int sum, vector<int> b, int aim, int i)
{
    if (sum > aim)
        return;

    if (i == n)
    {
        if (sum < aim)
            s++;
        else
        {
            for (int k = 0; k < n; k++)
            {
                if (a[k] > b[k])
                    break;
                if (a[k] < b[k])
                    return;
            }
            s++;
        }

        return;
    }

    for (int j = 0; j <= aim - sum; j++)
    {
        b.push_back(j);
        solve(sum + j, b, aim, i + 1);
        b.pop_back();
    }
}

vector<int> split(string s)
{
    string delimiter = " ";
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<int> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(stoi(token));
    }

    res.push_back(stoi(s.substr(pos_start)));
    return res;
}

int main()
{
    fastio;
    string sf;
    while (getline(cin, sf))
    {
        if (sf == "0")
            break;
        vector<int> ss = split(sf);
        int si = 0;
        for (int i = 1; i < ss.size(); i++)
        {
            a.push_back(ss[i]);
            si += ss[i];
        }

        n = ss[0];
        solve(0, vector<int>(), si, 0);

        cout << s << '\n';
        s = 0;

        a.clear();
    }

    return 0;
}
