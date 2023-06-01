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

    int N, l, p;
    cin >> N >> l >> p;
    vector<int> m(p);

    for (int i = 0; i < p; i++)
        cin >> m[i];

    vector<int> V(N);
    fill_n(V.begin(), N, 0);

    int f = 0;
    for (int i = 0; i < p; i++)
    {
        if (m[i] >= N * l)
        {
            V[N - 1]++;
            f = max(f, m[i] - N * l + l / 2);
        }
        else
        {
            double t = 1.0 * m[i] / l;
            V[int(t)]++;
            f = max(f, abs((int(t) * l + int(t + 1) * l) / 2 - m[i]));
        }
    }

    cout << f << '\n'
         << *max_element(all(V));

    return 0;
}
