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

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

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

string OctToBin(string octnum)
{
    long int i = 0;

    string binary = "";

    while (octnum[i])
    {
        switch (octnum[i])
        {
        case '0':
            binary += "000";
            break;
        case '1':
            binary += "001";
            break;
        case '2':
            binary += "010";
            break;
        case '3':
            binary += "011";
            break;
        case '4':
            binary += "100";
            break;
        case '5':
            binary += "101";
            break;
        case '6':
            binary += "110";
            break;
        case '7':
            binary += "111";
            break;
        default:
            cout << "\nInvalid Octal Digit "
                 << octnum[i];
            break;
        }
        i++;
    }

    return binary;
}

int main()
{
    fastio;
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int n = s.length();

        string grid;
        grid.push_back(s[n - 1]);
        grid.push_back(s[n - 2]);
        grid.push_back(s[n - 3]);

        grid = OctToBin(grid);

        int mx = -1;
        set<int> aim;
        for (int i = 0; i < 9; i++)
            if (grid[i] == '1')
            {
                aim.insert(i);
                if (mx < i)
                    mx = i;
            }

        if (aim.empty())
        {
            cout << "In progress";
            return 0;
        }
        int g[9];
        string temp;

        if (*aim.rend() > 5)
        {
            temp.push_back(s[n - 4]);
            temp.push_back(s[n - 5]);
            temp.push_back(s[n - 6]);

            temp = OctToBin(temp);
        }
        else if (*aim.rend() > 2)
        {
            temp.push_back(s[n - 4]);
            temp.push_back(s[n - 5]);
            temp = OctToBin(temp);
        }
        else
        {
            temp.push_back(s[n - 4]);
            temp = OctToBin(temp);
        }

        for (int i = 0; i < 9; i++)
        {
            if (aim.find(i) != aim.end())
            {
                if (temp[i] == '0')
                    g[i] = 1;
                else
                    g[i] = 2;
            }
        }

        if (g[0] == g[1] && g[1] == g[2])
            if (g[0] == 2)
                cout << "X wins";
            else
                cout << "O wins";
        else if (g[3] == g[4] && g[4] == g[5])
            if (g[3] == 2)
                cout << "X wins";
            else
                cout << "O wins";
        else if (g[6] == g[7] && g[7] == g[8])
            if (g[6] == 2)
                cout << "X wins";
            else
                cout << "O wins";
        else if (g[0] == g[3] && g[3] == g[6])
            if (g[0] == 2)
                cout << "X wins";
            else
                cout << "O wins";
        else if (g[1] == g[4] && g[4] == g[7])
            if (g[1] == 2)
                cout << "X wins";
            else
                cout << "O wins";
        else if (g[2] == g[5] && g[5] == g[8])
            if (g[2] == 2)
                cout << "X wins";
            else
                cout << "O wins";
        else if (g[0] == g[4] && g[4] == g[8])
            if (g[0] == 2)
                cout << "X wins";
            else
                cout << "O wins";
        else if (g[2] == g[4] && g[4] == g[6])
            if (g[2] == 2)
                cout << "X wins";
            else
                cout << "O wins";
        else if (aim.size() == 9)
            cout << "Cat's";
        else
            cout << "In progress";

        cout << "\n";
    }

    return 0;
}
