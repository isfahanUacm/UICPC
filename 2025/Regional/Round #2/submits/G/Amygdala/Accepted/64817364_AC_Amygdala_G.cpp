#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';

char f(char a1, char b1, char a2, char b2)
{
    if(a1 > b1) swap(a1, b1);
    if(a2 > b2) swap(a2, b2);

    if(a1 > a2)
    {
        swap(a1,a2);
        swap(b1,b2);
    }

    if(b1>a2 && b1<b2) return b1;
    else if(b1 < a2) return b1;
    else return a2;
}

void solve()
{
    cint(n);
    string s, t; cin >> s >> t;
    string ans;
    for(int i=0; i<n; i++) ans.push_back('1');

    for(int i=0; i<n/2; i++)
    {
//        cout << f(s[i], t[i], s[n-1-i], t[n-1-i]);
        ans[i] = ans[n-i-1] = f(s[i], t[i], s[n-1-i], t[n-1-i]);
    }
    if(n%2)
    {
        ans[n/2] = s[n/2];
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}