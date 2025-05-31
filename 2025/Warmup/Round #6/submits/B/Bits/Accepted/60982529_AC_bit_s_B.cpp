#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
    int n;  cin >> n;
    int s = sqrt(n);
    int ans = n -1;
    if(n %2 == 0){
        cout << n/2 << " " << n/2 << '\n';
    }
    else{
        for(int i=3; i<=s; i+=2){
            if(n%i == 0){
                int j = n/i;
                ans = min(ans, min(max(i,n-i),max(j,n-j)));
            }
        }
        cout << ans << " " << n - ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
    cin >> n;
    while(n--)
        solve();

    return 0;
}