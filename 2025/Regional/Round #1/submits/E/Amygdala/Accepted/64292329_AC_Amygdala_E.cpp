#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';
//const ll mod = 1e9+7;

//bool mark[105][105];
//int g[105][105];

void solve(int t)
{
    cout << "Case " << t << ": ";
    string s; cin >> s;
    string s1, s2;
    int ind = 0;
    while(s[ind] != ':') s1.push_back(s[ind++]);
    ind++;
    while(ind<s.size()) s2.push_back(s[ind++]);

    int n1, n2;
    n1 = stoi(s1);
    n2 = stoi(s2);

    int n1t = n1 + 1;
    int n2t = n2 + 6;

    if(n1t > n2t) cout << "YES\n";
    else if(n1t < n2t) cout << "NO\n";
    else
    {
        n2 *= 2;

        n1t = n1 + 2;
        n2t = n2 + 6;

        if(n1t > n2t) cout << "YES\n";
        else if(n1t < n2t) cout << "NO\n";
        else cout << "PENALTIES\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("ghanophobia.in", "r", stdin);

    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        solve( i+1);
    }

//    cout << generate('d', 5, 31, 12);

    return 0;
}