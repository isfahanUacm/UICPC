#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
    int n, c; cin >> n >> c;
    int ans = 1;
    int curr = c;
    for(int i=0; i<n; i++)
    {
        int x; cin >> x;
        if(x >= curr)
        {
            ans ++;
            curr = c;
        }
        else
        {
            curr -= x;
        }
    }
    cout << ans << '\n';
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