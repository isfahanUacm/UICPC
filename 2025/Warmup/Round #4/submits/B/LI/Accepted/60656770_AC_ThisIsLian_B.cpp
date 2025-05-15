#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define vi vector <int>

const int N = 2e5+9 , INF = 2e9;

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while(T--){
        int n , x;
        cin >> n >> x;
        vi vec;
        vec.clear();
        for(int i=0; i<n ; i++)
            if(i != x)
                vec.pb(i);
        if (x != n)vec.pb(x);
        for(int a : vec)
            cout << a << ' ';
       cout << endl;
    }
}


