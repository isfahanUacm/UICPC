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

const int N = 301;
int a[N][N][N];
int n, m;

void constructLps(vector<int> &pat, vector<int> &lps)
{

    // len stores the length of longest prefix which
    // is also a suffix for the previous index
    int len = 0;

    // lps[0] is always 0
    lps[0] = 0;

    int i = 1;
    while (i < pat.size())
    {

        // If characters match, increment the size of lps
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }

        // If there is a mismatch
        else
        {
            if (len != 0)
            {

                // Update len to the previous lps value
                // to avoid reduntant comparisons
                len = lps[len - 1];
            }
            else
            {

                // If no matching prefix found, set lps[i] to 0
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> search(vector<int> &pat, vector<int> &txt)
{
    int n = txt.size();
    int m = pat.size();

    vector<int> lps(m);
    vector<int> res;

    constructLps(pat, lps);

    // Pointers i and j, for traversing
    // the text and pattern
    int i = 0;
    int j = 0;

    while (i < n)
    {

        // If characters match, move both pointers forward
        if (txt[i] == pat[j])
        {
            i++;
            j++;

            // If the entire pattern is matched
            // store the start index in result
            if (j == m)
            {
                res.push_back(i - j);

                // Use LPS of previous index to
                // skip unnecessary comparisons
                j = lps[j - 1];
            }
        }

        // If there is a mismatch
        else
        {

            // Use lps value of previous index
            // to avoid redundant comparisons
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return res;
}

int check(int x, int a1, int b1, vector<vector<int>> &arr)
{
    if (a1 + n >= N || b1 + m >= N)
        return 0;
    for (int i = a1; i < a1 + n; i++)
    {
        for (int j = b1; j < b1 + m; j++)
        {
            if (arr[i - a1][j - b1] != a[x][i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

int32_t main()
{
    fast for (int x = 1; x <= (N / 3); x++)
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
    vector<int> v1[101];
    for (int x = 1; x <= (N / 3); x++)
    {
        for (int i = 0; i < N; i++)
        {
            if ((i / x) % 2 == 1)
                v1[x].pb(0);
            else
                v1[x].pb(1);
        }
    }
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            return 0;
        }
        vector<vector<int>> arr, arr1;
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
        arr1.resize(m);
        for (int j = 0; j < m; j++)
        {
            arr1[j].resize(n);
            for (int i = 0; i < n; i++)
            {
                if (arr[i][j] == 0)
                    arr1[j][i] = 0;
                else
                    arr1[j][i] = 1;
            }
        }
        int cnt = 0, x1 = 0;
        for (int x = 1; x <= N / 3; x++)
        {
            vector<int> res = search(arr[0], v1[x]);
            for (int w = 0; w < res.size(); w++)
            {
                if (res[w] - res[0] >= 2 * x)
                    break;
                vector<int> v3;
                for (int i = 0; i < N; i++)
                    v3.pb(a[x][i][res[w]]);
                vector<int> res1 = search(arr1[0], v3);
                for (int k = 0; k < res1.size(); k++)
                {
                    if (res1[k] - res[0] >= 2 * x)
                        break;
                    if (check(x, res[w], res1[k], arr))
                    {
                        if (cnt == 0)
                            cnt += 1, x1 = x;
                        else if (cnt == 1)
                        {
                            cnt = 2, x = N;
                        }
                        w = res.size();
                        k = res1.size();
                        break;
                    }
                }
            }
        }
        if (cnt == 0)
            cout << -1 << endl;
        else if (cnt == 1)
            cout << x1 << endl;
        else
            cout << 0 << endl;
    }
}