#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    loop(n, i) cin >> a[i];
    vector<int> g(n), r(n), d(n);
    loop(n, i)
    {
        cin >> r[i] >> g[i] >> d[i];
    }

    int sum = 0;

    for(int i=0; i<n; i++)
    {
        sum += a[i];

        int A = (sum+d[i]) % (r[i] + g[i]);
        if(A < g[i])
            continue;
        A -= g[i];
        sum += r[i] - A;
    }

    cout << sum;
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