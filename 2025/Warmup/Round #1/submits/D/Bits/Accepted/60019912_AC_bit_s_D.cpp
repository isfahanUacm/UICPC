#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
    int n, k, m; cin >> n >>  m >> k;
    vector<int> v(n);
    loop(n, i) cin >> v[i];
    std::sort(v.begin(), v.end());
    int cnt = 0, i = 0;
    for(; i<n;){
        int j =1;
        for(; j+i<n&&j<k; j++){
            if(v[j+i]-v[i] > m)
                break;
        }
        i += j;
        cnt++;
    }
    cout << cnt << '\n';
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