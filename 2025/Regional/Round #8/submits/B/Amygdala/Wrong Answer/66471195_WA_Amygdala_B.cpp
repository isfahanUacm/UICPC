#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';


void solve()
{
    int n; cin >> n;
    while(n){
        string s;
        cin >> s;
        int st = 0, en = 0;
        for (int i = 0; i < n; i++) {
            if (s[0] == s[i])
                st++;
            else
                break;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[0] == s[i])
                en++;
            else
                break;
        }
        if (st == n) {
            cout << s << s[0] << '\n';
            cin >> n;
            continue;
        }
        for (int i = 0; i < n - en; i++)
            cout << s[i];
        for (int i = 0; i < max(st, en); i++)
            cout << s[0];
        for (int i = st; i < n; i++)
            cout << s[i];
        cout << '\n';
        cin >> n;
    }
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