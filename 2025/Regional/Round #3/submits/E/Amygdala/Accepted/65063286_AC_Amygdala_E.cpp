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
    vecInt pref_sum(n+1, 0);
    v.push_back(-1);
    int p; cin >> p;
    int number_of_query = 0;

    while(p < 70 && number_of_query++ < 125)
    {
        int ps = 0;
        for(int i=0; i<n; i++)
        {
            if(v[i] == 1) ps ++;

            pref_sum[i+1] = ps;
        }

        int l, r;
        int cur_mx = -1;
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                if(((j - i)) - 2*(pref_sum[j+1] - pref_sum[i]) > cur_mx)
                {
                    cur_mx = ((j - i)) - 2*(pref_sum[j+1] - pref_sum[i]);
                    l = i;
                    r = j;
                }
            }
        }

        cout << l+1 << ' ' << r+1 << endl;

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