#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> a(n);
    loop(n, i) cin >> a[i];
    if(m==1){
        cout << "1\n";
    }
    vector<int> v(n-1);
    for(int i=0; i<n-1; i++)
        v[i] = abs(a[i+1]-a[i]);
    sort(v.rbegin(),v.rend());
    if(v[m-1] == v[m-2])
        cout << "-1\n";
    else
        cout << v[m] << '\n';
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