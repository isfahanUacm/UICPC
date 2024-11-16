#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve()
{
    int n ; cin >> n ;
    vector<int> h(n),v(n) ;
    for(int i = 0  ; i < n ; i ++)
    {
        cin >> h[i] ;
    }
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> v[i] ;
    }
    int sub = v[0] - h[0] ;
    if(sub < 0)
    {
        cout << 0;
        return;
    }
    bool flag = false ;
    for(int i = 0 ; i < n ; i ++)
    {
        h[i] += sub ;
        if(v[i] > h[i])
        {
            cout<<sub+1;
            return ;
        }
        if(h[i] > v[i])
        {
            cout<<sub;
            return ;
        }
    }
    cout<<sub;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    solve();

    return 0;
}
