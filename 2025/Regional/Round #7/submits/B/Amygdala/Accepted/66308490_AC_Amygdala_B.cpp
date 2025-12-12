#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second


const int N = 2e5+9;

void solve()
{
    string s; cin >> s;

    if(s.size() == 2)
    {
        if(s[0] == '0' || s[1] == '0')
        {
            cout << -1;
            return;
        }
        cout << s[0] << ' ' << s[1];
    }
    else if(s.size() == 4)
    {
        if(s[0]=='0' || s[2]=='0')
        {
            cout << -1;
            return;
        }
        cout << s[0] << s[1] << ' ' << s[2] << s[3];
    }
    else if(s.size() == 3)
    {
        if(s[1] == '0')
        {
            cout << s[0] << s[1] << ' ' << s[2];
            return;
        }
        else if(s[2] == '0')
        {
            cout << s[0] << ' ' << s[1] << s[2];
            return;
        }
        else
        {
            cout << -1;
            return;
        }
    }

    else cout << "-1";
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
