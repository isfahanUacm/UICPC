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

pair<ll, ll> continius(stack<pair<ll, ll>> a)
{
    while (a.size() > 1)
    {
        pair<ll, ll> s1 = a.top();
        a.pop();
        pair<ll, ll> s2 = a.top();
        a.pop();

        ll v1 = s1.first * s2.second + s1.second * s2.first;
        ll v2 = s1.second * s2.second;

        a.push({v2, v1});
    }
    return {a.top().second, a.top().first};
}

vector<ll> make(pair<ll, ll> a)
{
    vector<ll> slv;
    while (a.first % a.second != 0)
    {
        slv.push_back(a.first / a.second);
        a = {a.second, a.first - slv[slv.size() - 1] * a.second};
    }
    slv.push_back(a.first / a.second);
    return slv;
}

int main()
{
    fastio;

    int n1, n2;
    cin >> n1 >> n2;

    stack<pair<ll, ll>> a1, a2;

    ll t;
    for (int i = 0; i < n1 - 1; i++)
    {
        cin >> t;
        a1.push({t, 1});
    }
    cin >> t;
    a1.push({1, t});

    for (int i = 0; i < n2 - 1; i++)
    {
        cin >> t;
        a2.push({t, 1});
    }
    cin >> t;
    a2.push({1, t});

    pair<ll, ll> num1 = continius(a1);
    pair<ll, ll> num2 = continius(a2);

    pair<ll, ll> sum = {num1.first * num2.second + num2.first * num1.second, num1.second * num2.second};
    pair<ll, ll> sub = {num1.first * num2.second - num2.first * num1.second, num1.second * num2.second};
    pair<ll, ll> mul = {num1.first * num2.first, num1.second * num2.second};
    pair<ll, ll> div = {num1.first * num2.second, num1.second * num2.first};

    for (ll u : make(sum))
        cout << u << ' ';
    cout << '\n';
    for (ll u : make(sub))
        cout << u << ' ';
    cout << '\n';

    for (ll u : make(mul))
        cout << u << ' ';
    cout << '\n';

    for (ll u : make(div))
        cout << u << ' ';

    return 0;
}
