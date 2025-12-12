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
    int q;  cin >> q;
    vector<vector<int>> v(100);
    int len=0;
    while(q--){
        int cmd;    cin >> cmd;
        if(cmd == 1){
            len++;
        }
        else if(cmd == 2){
            int i,x;    cin >> i >> x;
            i--;
            v[i].push_back(x);
        }
        else if(cmd == 3){
            int i,j; cin >> i >> j;
            i--; j--;
            cout << v[i][j] << '\n';
        }
    }

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
