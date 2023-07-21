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

bool isPrime(long long num)
{
    if (num <= 1)
        return false;
    if (num <= 3)
        return true;

    ll range = sqrt(num);

    if (num % 2 == 0 || num % 3 == 0)
        return false;

    for (int i = 5; i <= range; i += 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return false;

    return true;
}

unordered_map<long long, long long> ss;
void primeFactors(long long n)
{
    while (n % 2 == 0)
    {
        ss[2]++;
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            ss[i]++;
            n = n / i;
        }
    }

    if (n > 2)
    {
        ss.insert({n, 1});
    }
}

int main()
{
    long long a, b;
    cin >> a >> b;
    if (isPrime(a) && isPrime(b) && a != b)
    {
        cout << "full credit";
        return 0;
    }

    if (a == b)
    {
        cout << "no credit";
        return 0;
    }
    else if (!isPrime(a) || !isPrime(b))
    {
        primeFactors(a);
        unordered_map<ll, ll> s1 = ss;
        primeFactors(b);
        unordered_map<ll, ll> s2 = ss;

        for (auto t : s2)
        {
            if (s1.find(t.first) != s1.end())
            {
                s1[t.first] += t.second;
            }
            else
                s1[t.first] = t.second;
        }

        for (auto t : s1)
        {
            if (t.second > 1)
            {
                cout << "no credit";
                return 0;
            }
        }
        cout << "partial credit";
    }
    else
        cout << "no credit";

    return 0;
}