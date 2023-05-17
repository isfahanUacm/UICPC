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

// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2")

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

int precedence(char op)
{
    if (op == '+' || op == '*')
        return 1;
    return 0;
}

ll evaluate(string tokens)
{
    stack<pair<ll, char>> s;
    for (int i = 0; i < tokens.length(); i++)
    {
        if (tokens[i] == ')')
        {
            pair<ll, char> ss;
            while (s.top().second != '(')
            {
                pair<ll, char> s1 = s.top();
                s.pop();

                pair<ll, char> o = s.top();
                if (o.second == '(')
                {
                    ss = s1;
                    break;
                }
                s.pop();

                pair<ll, char> s2 = s.top();
                s.pop();

                if (o.second == '+')
                {
                    ss = make_pair(s1.first + s2.first, ' ');
                }
                else
                {
                    ss = make_pair(s1.first * s2.first, ' ');
                }
            }
            s.pop();
            s.push(ss);
        }
        else if (precedence(tokens[i]) == 1 || tokens[i] == '(')
            s.push(make_pair(-1, tokens[i]));
        else
        {
            string num;
            while (tokens[i] >= '0' && tokens[i] <= '9')
            {
                num.push_back(tokens[i]);
                i++;
            }
            i--;
            s.push({stoll(num), ' '});
        }
    }

    ll val = 0;
    while (s.size() > 1)
    {
        pair<ll, char> s1 = s.top();
        s.pop();

        pair<ll, char> o = s.top();
        s.pop();

        if (o.second == '(')
        {
            s.push(s1);
            continue;
        }

        pair<ll, char> s2 = s.top();
        s.pop();

        s.push({s1.first + s2.first, ' '});
    }

    return s.top().first;
}

int main()
{
    fastio;

    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);

    string a;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            a.push_back(s[i]);
            i++;
        }
        else if (s[i] == ')')
        {
            a.pop_back();
            a.push_back(s[i]);
        }
        else
        {
            a.push_back(s[i]);
        }
    }

    int c = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '(')
            c++;
        else if (a[i] == ')')
            c--;
        else if (a[i] == ' ')
        {
            if (c % 2 == 0)
                a[i] = '+';
            else
                a[i] = '*';
        }
    }

    string f;
    bool flg = true;
    f.push_back(a[0]);
    for (int i = 1; i < a.length() - 1; i++)
    {
        if (a[i] >= '0' && a[i] <= '9')
        {
            if (a[i - 1] == '(' && a[i + 1] == ')')
            {
                f.pop_back();
                f.push_back(a[i]);
                i++;

                if (i == a.length() - 1)
                    flg = false;
            }
            else
                f.push_back(a[i]);
        }
        else
            f.push_back(a[i]);
    }
    if (flg)
        f.push_back(a[a.length() - 1]);

    cout << evaluate(f);

    return 0;
}