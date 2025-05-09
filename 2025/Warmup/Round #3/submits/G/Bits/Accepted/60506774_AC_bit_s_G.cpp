#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);




void solve()
{
    int n,m,c;
    cin >> n >> m >> c;
    map<int,int> mp;
    int a = 0, b=0;
    for(int i = 0 ; i < n ; i ++)
    {
        int l, r ;
        cin >> l >> r;
        if(mp[l] < c){
            mp[l]++;
            a++;
        }
        else if(mp[r] < c) {
            mp[r]++;
            b++;
        }
    }
    cout << a << " " << b << '\n';
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