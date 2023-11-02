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

const int mxh = 140;
const int mxw = 120;

int grid[mxh][mxw];
int ps[mxh + 1][mxw + 1];

int Partition(vector<float>& arr, int l, int r)
{
    int i = l, j = l;
    float lst = arr[r];
    while (j < r)
    {
        if (arr[j] < lst)
        {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
    swap(arr[i], arr[r]);
    return i;
}

int randomPartition(vector<float>& arr, int l, int r)
{
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(arr[l + pivot], arr[r]);
    return Partition(arr, l, r);
}

void MedianUtil(vector<float>& arr, int l, int r, int k, float &a, float &b)
{
    if (l <= r)
    {
        int partitionIndex = randomPartition(arr, l, r);

        if (partitionIndex == k)
        {
            b = arr[partitionIndex];
            if (a != -1)
                return;
        }

        else if (partitionIndex == k - 1)
        {
            a = arr[partitionIndex];
            if (b != -1)
                return;
        }

        if (partitionIndex >= k)
            return MedianUtil(arr, l, partitionIndex - 1, k, a, b);
        else
            return MedianUtil(arr, partitionIndex + 1, r, k, a, b);
    }

    return;
}

void findMedian(vector<float>& arr, int n)
{
    float a = -1, b = -1;
    float ans;

    if (n % 2 == 1)
    {
        MedianUtil(arr, 0, n - 1, n / 2, a, b);
        ans = b;
    }

    else
    {
        MedianUtil(arr, 0, n - 1, n / 2, a, b);
        ans = (a + b) / 2.0;
    }

    cout << fixed << showpoint << setprecision(6) << ans;
}

void solve()
{
    int h, w;
    cin >> h >> w;

    int a, b;
    cin >> a >> b;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> grid[i][j];

    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            ps[i][j] = grid[i - 1][j - 1] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
        }

    vector<float> res;
    for (int i = 0; i < h; i++)
    {
        for (int j = i; j < h; j++)
        {
            for (int k = 0; k < w; k++)
            {
                for (int p = k; p < w; p++)
                {
                    int s = (j - i + 1) * (p - k + 1);
                    int val = ps[j + 1][p + 1] - ps[j + 1][k] - ps[i][p + 1] + ps[i][k];
                    if (s >= a && s <= b)
                        res.pb(1.0 * val / s);
                }
            }
        }
    }

    findMedian(res, sz(res));

}

int32_t main()
{
    fastio;
    int t = 1;
    while (t--)
        solve();

    return 0;
}
