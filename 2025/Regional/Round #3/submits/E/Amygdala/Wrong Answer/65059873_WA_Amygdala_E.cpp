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

const int N = 200;
double a[N] , mx[N] , mn[N];
string s[N];


void solve()
{
    cint(n);
    cout << 1 << ' ' << n << endl;

    vecInt v(n);
    vin(v);
    v.push_back(-1);
    int p; cin >> p;
    int i = 0;

    while(p < 70 && i++ < 125)
    {
        int l, r;
        int l_res=0, r_res=-1;
        int cnt=0;
        for(int i=0; i<=n; i++)
        {
            if(v[i] == 0)
            {
                if(cnt == 0) l = i;
                r = i;
                cnt++;
            }
            else
            {
                if(cnt > r_res-l_res+1)
                {
                    l_res = l;
                    r_res = r;
                }
                cnt = 0;
            }
        }

        cout << l_res+1 << ' ' << r_res+1 << endl;

        for(int i=0; i<n; i++) cin >> v[i];
        cin >> p;
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

//    for(int i=1; i<20; i++) cout << i << ':' << is_prime(i) << endl;
    return 0;
}