#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    vector<double> v(20);
    v[0] = 2.00;
    v[1] = 1.00;
    v[2] = 0.5;
    v[4] = 0.25;
    v[8] = 0.125;
    v[16] = 0.0625;

    int n; cin >> n;
    double sum = 0.00;
    for(int i=0; i<n; i++)
    {
        int x; cin >> x;
        sum += v[x];
    }

    cout << sum;
}

int main()
{
    solve();
    return 0;
}
