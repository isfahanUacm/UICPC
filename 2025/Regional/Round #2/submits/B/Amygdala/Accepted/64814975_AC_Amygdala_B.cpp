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
    int n, p;   cin >> n >> p;
    vector<int> a(p,0), b(p,0), c(p,0);
    for(int i=0; i<n; i++){
        for(int j=0; j<p; j++){
            char cmd;
            int num;  cin >> cmd >> num;
            if(cmd == '+'){
                a[j]++;
                b[j]++;
            }
            else if(num > 0){
                b[j]++;

            }
            c[j] += num;
        }
    }
    for(int i=0; i<p; i++)
        cout << a[i] << " " << b[i] << " " << c[i] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }

//    for(int i=1; i<20; i++) cout << i << ':' << is_prime(i) << endl;
    return 0;
}