#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll const INF = 1e16;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    int s = sqrt(n);
    ll ans = 0;
    for(int i = 1; i<=s; i++){
        if(n%i == 0){
            int j = n/i;
            ll minsum=INF, maxsum=0, sum=0;
            for(int k=0; k<j; k++){
                sum = 0;
                for(int l=0; l<i; l++)
                    sum += v[l+k*i];
                maxsum = max(sum, maxsum);
                minsum = min(sum,minsum);
            }
            ans = max(maxsum-minsum,ans);
            minsum=INF, maxsum=0, sum=0;
            for(int k=0; k<i; k++){
                sum = 0;
                for(int l=0; l<j; l++)
                    sum += v[l+k*j];
                maxsum = max(sum, maxsum);
                minsum = min(sum,minsum);
            }
            ans = max(maxsum-minsum,ans);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
