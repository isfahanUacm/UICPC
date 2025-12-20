#include <bits/stdc++.h>
using namespace std;

#define ll long long
// #define int long long
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

const int MOD = 1e9 + 7, SQ = 548, LG = 20, INF = LLONG_MAX;

ll pw(ll a, ll b) { return b == 0 ? 1LL : (pw(a * a, b / 2) * (b % 2 == 0 ? 1LL : a)); }
ll pwm(ll a, ll b) { return b == 0 ? 1LL : (pw(a * a % MOD, b / 2) % MOD * (b % 2 == 0 ? 1LL : a)) % MOD; }

const int N = 201;
int a[N][N][N];
int n, m;

int check(int x, int a1, int b1, vector<vector<int>> &arr)
{
    if (a1 + n >= N || b1 + m >= N)
        return 0;
    for (int i = a1; i < a1 + n; i++)
    {
        for (int j = b1; j < b1 + m; j++)
        {
            if (arr[i - a1][j - b1] != a[x][i][j])
                return 0;
        }
    }
    return 1;
}

int32_t main()
{
    fast for (int x = 1; x <= (N / 2); x++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if ((i / x + j / x) % 2 == 0)
                    a[x][i][j] = 1;
                else
                    a[x][i][j] = 0;
            }
        }
    }
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            return 0;
        }
        vector<vector<int>> arr;
        arr.resize(n);
        for (int i = 0; i < n; i++)
        {
            arr[i].resize(m);
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                if (s[j] == '.')
                    arr[i][j] = 0;
                else
                    arr[i][j] = 1;
            }
        }
        int cnt = 0, mrk;
        for (int x = 1; x <= (N / 2); x++)
        {
            for (int a = 0; a <= 2 * x; a++)
                for (int b = 0; b <= 2 * x; b++)
                {
                    if (check(x, a, b, arr))
                    {
                        // cout << x << a << b << endl;
                        if (cnt == 0)
                            cnt++, mrk = x;
                        else if (cnt == 1)
                        {
                            cnt = 2;
                            x = N + 1, a = 2 * x, b = 2 * x;
                            break;
                        }
                        a = 2 * x, b = 2 * x;
                        break;
                    }
                }
        }
        if (cnt > 1)
        {
            cout << 0 << endl;
        }
        else if (cnt == 0)
        {
            cout << -1 << endl;
        }
        else
            cout << mrk << endl;
    }
}