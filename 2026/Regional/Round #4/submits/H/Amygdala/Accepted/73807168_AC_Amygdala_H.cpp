#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define vi vector <int>
#define all(x) x.begin(),x.end()

const int N = 1e6+9 , INF = 1e18 ;
int a[N];

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1;
    cin >> T;
    while(T--) {
       int n;
       cin >> n;
       int ind=-1;
       for(int i=0 ; i<n ; i++){
           cin >> a[i];
       }
        for(int i=0 ; i<n ; i++){
            if(a[i]!=1){
                ind=i;
                break;
            }

        }
        if(ind == -1){
            cout << 0 << endl;
            continue;
        }
        int ind2=n;
        for(int i=ind ; i<n ; i++){
            if(a[i]!=a[ind]){
                ind2=i;
                break;
            }
        }
        bool ok=1;
        for(int i=ind2 ; i<n ; i++){
            if(a[i]!=1){
                ok=0;
                break;
            }
        }
        cout << (ok ? 1 : 2) << endl;

    }

}
