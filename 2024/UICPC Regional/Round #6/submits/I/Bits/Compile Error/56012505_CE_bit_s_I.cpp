#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int maxN = 1e6+5;
const int INF = 1e9+7;

ll arr[maxN];
ll t[maxN];
void solve(){
    int n ; cin >>n ;
    vector<int> h(n),v(n) ;
    int maxh= 0, maxv = 0;
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> h[i];
        maxh = max(maxh,h[i]);
    }
    for(int i = 0 ;i < n ; i ++)
    {
        cin >> v[i] ;
        maxv = max(maxv,v[i]);
    }
    int cnt = maxv - maxh;...........
    if(cnt <= 0){
        cout << 0 << '\n';
        return;
    }

    cout<< cnt <<'\n' ;
}

int main()
{
     solve();

    return 0;
}
