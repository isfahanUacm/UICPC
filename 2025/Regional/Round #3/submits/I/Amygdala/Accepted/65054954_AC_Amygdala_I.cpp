#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';

int cnt[50];

void solve()
{
    int n; cin >> n;
    vector<string> ans;
    for(int i=0; i<n; i++){
        int p;  cin >> p;
        vector<string> v(p);
        for(int j=0; j<p; j++)
            cin >> v[j];
        std::sort(v.begin(), v.end());
        if(i==0){
            ans.push_back(v[0]);
            continue;
        }
        for(int j=0; j<p; j++)
            if(v[j] >= ans[i-1]) {
                ans.push_back(v[j]);
                break;
            }
        if(ans.size() != i+1){
            cout << "impossible\n";
            return;
        }
    }
    for(string s : ans)
        cout << s << '\n';
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