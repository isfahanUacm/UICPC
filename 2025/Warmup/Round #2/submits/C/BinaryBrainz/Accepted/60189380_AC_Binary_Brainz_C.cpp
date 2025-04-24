#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;

string s;
int ind  = 0;

ll fun(){

    if(s[ind + 1] == ')'){
        ind+=2;
        return 1;
    }
    else {
        ind++;
        ll res = fun();
        while(s[ind] == '('){
            ll res2 = fun();
            res *= res2;
        }
        res++;
        ind++;
        return res;
    }
}

void solve()
{

    int n;
    cin >> n;
    cin >> s;
    ll sum = 1;

    int len =  s.length();
    while(ind < len){
        sum *= fun();
    }

    cout << sum;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
        if (t != 0)
            cout << endl;
    }
}