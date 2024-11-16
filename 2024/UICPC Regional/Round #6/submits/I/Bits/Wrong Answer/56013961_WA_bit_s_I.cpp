#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> fibo(35);

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
        cout << 0 <<'\n' ;
        return;
    }
    bool flag = false ;
    for(int i = 0 ; i < n ; i ++)
    {
        h[i] += sub ;
        if(h[i] < v[i])
        {
            sub++;
            cout<<sub<<'\n';
            return ;
        }
    }
    cout<<sub<<'\n' ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


//    for(auto x : fibo)
//        cout << x << " ";
//    cout << flush;

    solve();

    return 0;
}
