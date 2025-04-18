#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
    int n; cin >> n;
    vector<long long> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    long long sum = 0, ans =0 ;
    for(int i=0; i<n; i++){
        sum += v[i];
        if(sum < 0)
            ans = max(ans, -sum);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
//    cin >> n;
    while(n--)
        solve();

    return 0;
}