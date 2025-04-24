#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
const ll  mod  = 1e9+7;

void solve()
{
    vector<int> x(3), y(3);
    for(int i=0; i<3; i++)
        cin >> x[i] >> y[i];
    int a = x[0], b=y[1];
    if(a==x[2] || b==y[2]){
        a = x[1];
        b = y[0];
    }
    cout << 1 << '\n' << a << " " << b << '\n';
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