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

    int r, c;
    cin >> r >> c;



    int grid[r][c];
    int rows[r];
    int columns[c];

    for (int i = 0; i < r; i++)
        cin >> rows[i];
    for (int j = 0; j < c; j++)
        cin >> columns[j];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            grid[i][j] = min(rows[i], columns[j]);
        }
    }

    bool valid = true;

    for (int i = 0; i < r; i++)
    {
        int mx = grid[i][0];
        for (int j = 0; j < c; j++)
        {
            if(grid[i][j] > mx) mx = grid[i][j];
        }
        if (mx != rows[i])
        {
            valid = false;
            break;
        }
    }

    for (int i = 0; i < c; i++)
    {
        int mx = grid[0][i];
        for (int j = 0; j < r; j++)
        {
            if(grid[j][i] > mx) mx = grid[j][i];
        }
        if (mx != columns[i])
        {
            valid = false;
            break;
        }
    }

    if (valid)
        cout << "possible";
    else
        cout << "impossible";
    return 0;
}
