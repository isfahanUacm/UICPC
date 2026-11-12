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

const int N = 1e5+9 , INF = 1e18 , mod=998244353 ;
int cnt[N];
vi vec[N];
set <int> s;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1;
    //cin >> T;
    while(T--) {
        int q;
        cin >> q;
        for(int i=2 ; i<N ; i++){
            if(vec[i].empty()){
                for(int j=i ; j<N ; j+=i){
                    vec[j].pb(i);
                }
            }

        }
        while(q--){
            int t , x;
            cin >> t >> x;
            if(t == 1){
                for(int p : vec[x]){
                    s.insert(p);
                    int temp=x , c=0;
                    while(temp%p == 0){
                        temp/=p;
                        c++;
                    }
                    cnt[p]=min(cnt[p]+c , 20ll);
                }
            }
            else if(t == 2){
                vi v;
                for(int p : s){
                    cnt[p]=min(cnt[p]*x , 20ll);
                    if(cnt[p]==20){
                        v.pb(p);
                    }
                }
                for(int p : v){
                    s.erase(p);
                }
            }
            else{
                bool yes=1;
                for(int p : vec[x]){
                    s.insert(p);
                    int temp=x , c=0;
                    while(temp%p == 0){
                        temp/=p;
                        c++;
                    }
                    if(cnt[p] < c){
                        yes=0;
                        break;
                    }
                }
                cout << (yes ? "Yes" : "No") << endl;
            }
        }

    }

}