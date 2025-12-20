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
        int a = -1;
        for(int j=n-1; j>0; j--){
            int k=j, i=0;
            for(; i<n; i++){
                if(s[i] != s[k]) break;
                k++;
                if(k==n)break;
            }
            if(k==n)
                a = i;
        }
        for (int i = 0; i < n - a-1; i++)
            cout << s[i];
        cout << s;

        cin >> n;
        if(n)
            cout << '\n';
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