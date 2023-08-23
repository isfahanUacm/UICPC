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

bool valid(int i, int base, int node, int value, vector<vi> &edge, vector<int> &table)
{
    while (table[value] != -1)
    {
        int change = table[value];
        int newV = edge[change][0] + edge[change][1] - value;

        table[value] = node;
        node = change;
        value = newV;

        if ((node == i) && (value == edge[i][0]))
            return false;
    }
    table[value] = node;
}

bool valid1(int i, int base, int node, int value, vector<vi> edge, vector<int> table)
{
    while (table[value] != -1)
    {
        int change = table[value];
        int newV = edge[change][0] + edge[change][1] - value;

        table[value] = node;
        node = change;
        value = newV;

        if ((node == i) && (value == edge[i][0]))
            return false;
    }
    table[value] = node;
}

void solve()
{
    int nW, nT;
    cin >> nW >> nT;

    vector<vi> edge(nT, vi(2));
    vector<int> table(nT, -1);

    for (int i = 0; i < nW; i++)
    {
        cin >> edge[i][0] >> edge[i][1];
    }

    bool flag = true;
    for (int i = 0; i < nW; i++)
    {
        if (table[edge[i][0]] == -1)
            table[edge[i][0]] = i;
        else if (table[edge[i][1]] == -1)
            table[edge[i][1]] = i;
        else
        {
            if (valid1(i, edge[i][0], i, edge[i][0], edge, table))
            {
                valid(i, edge[i][0], i, edge[i][0], edge, table);
                continue;
            }
            else if (valid1(i, edge[i][1], i, edge[i][1], edge, table))
            {
                valid(i, edge[i][1], i, edge[i][1], edge, table);
                continue;
            }
            else
            {
                cout << "rehash necessary\n";
                flag = false;
                break;
            }
        }
    }
    if (flag)
        cout << "successful hashing\n";
}

int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
