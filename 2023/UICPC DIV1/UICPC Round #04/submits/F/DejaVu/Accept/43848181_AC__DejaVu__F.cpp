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

string convertNum(vector<string> s)
{
    if (s[0] == "***" && s[1] == "* *" && s[2] == "* *" && s[3] == "* *" && s[4] == "***")
    {
        return "0";
    }
    else if (s[0] == "  *" && s[1] == "  *" && s[2] == "  *" && s[3] == "  *" && s[4] == "  *")
    {
        return "1";
    }
    else if (s[0] == "***" && s[1] == "  *" && s[2] == "***" && s[3] == "*  " && s[4] == "***")
    {
        return "2";
    }
    else if (s[0] == "***" && s[1] == "  *" && s[2] == "***" && s[3] == "  *" && s[4] == "***")
    {
        return "3";
    }
    else if (s[0] == "* *" && s[1] == "* *" && s[2] == "***" && s[3] == "  *" && s[4] == "  *")
    {
        return "4";
    }
    else if (s[0] == "***" && s[1] == "*  " && s[2] == "***" && s[3] == "  *" && s[4] == "***")
    {
        return "5";
    }
    else if (s[0] == "***" && s[1] == "*  " && s[2] == "***" && s[3] == "* *" && s[4] == "***")
    {
        return "6";
    }
    else if (s[0] == "***" && s[1] == "  *" && s[2] == "  *" && s[3] == "  *" && s[4] == "  *")
    {
        return "7";
    }
    else if (s[0] == "***" && s[1] == "* *" && s[2] == "***" && s[3] == "* *" && s[4] == "***")
    {
        return "8";
    }
    else if (s[0] == "***" && s[1] == "* *" && s[2] == "***" && s[3] == "  *" && s[4] == "***")
    {
        return "9";
    }
    else
    {
        return "B";
    }
}

int main()
{
    fastio;

    vector<vector<char>>(5, vector<char>(35));
    string s1, s2, s3, s4, s5;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);
    getline(cin, s4);
    getline(cin, s5);

    int n = (s1.length() + 1) / 4;

    string aim = "";

    for (int i = 0; i < n; i++)
    {
        vector<string> ss;
        int s = i * 4;
        if (i == 0)
            s = 0;

        ss.push_back(s1.substr(s, 3));
        ss.push_back(s2.substr(s, 3));
        ss.push_back(s3.substr(s, 3));
        ss.push_back(s4.substr(s, 3));
        ss.push_back(s5.substr(s, 3));

        string t = convertNum(ss);
        if (t == "B")
        {
            cout << "BOOM!!";
            return 0;
        }
        aim += t;
    }

    while (!aim.empty() && aim[0] == '0')
    {
        aim = aim.substr(1);
    }

    if (aim.empty())
        cout << "BEER!!";
    else
    {
        int t = stoi(aim);
        if (t % 6 == 0)
            cout << "BEER!!";
        else
            cout << "BOOM!!";
    }
    
    return 0;
}
