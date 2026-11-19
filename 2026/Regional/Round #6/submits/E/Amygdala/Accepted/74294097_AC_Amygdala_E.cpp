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

const int N = 1e3+9 , INF = 1e18 , mod=1006903069;
string a[N] , b[N];
int dis[N][N];

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1;
    cin >> T;
    while(T--) {
        int n , m;
        cin >> n >> m;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        for(int i=0 ; i<n ; i++){
            cin >> b[i];
        }
        int s1 , s2 , d;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(a[i][j]=='S'){
                    s1=i*m+j;
                }
                if(b[i][j]=='S'){
                    s2=i*m+j;
                }
                if(b[i][j]=='D'){
                    d=i*m+j;
                }
            }
        }
        for(int i=0 ; i<n*m ; i++){
            fill(dis[i]  , dis[i]+(m*n) , INF);
        }
        dis[s1][s2]=0;
        queue<pii> q;
        q.push({s1 , s2});
        while(!q.empty()){
            pii p=q.front();
            int xa=p.F/m , ya=p.F%m , xb=p.S/m , yb=p.S%m;
            //cout << p.F << ' ' << p.S << endl;
            for(int i=-1 ; i<=1 ; i++){
                for(int j=-1 ; j<=1 ; j++){

                    if(!((i==0 || j== 0 )&& i!=j)){
                        continue;
                    }
                    if(xa+i < 0 || ya+j<0 || xa+i >= n || ya+j >= m){
                        continue;
                    }
                    if(a[xa+i][ya+j]=='X'){
                        continue;
                    }
                    int f=(xa+i)*m+(ya+j), s;
                    if(xb+i < 0 || yb+j<0 || xb+i >= n || yb+j >= m || b[xb+i][yb+j]=='X'){
                        s=p.S;
                    }
                    else{
                        s=(xb+i)*m+(yb+j);
                    }
                    if(dis[p.F][p.S]+1 < dis[f][s]){

                        dis[f][s]=dis[p.F][p.S]+1;

                        q.push({f , s});
                    }
                }
            }
            q.pop();

        }
        int ans=INF;
        for(int i=0 ; i<n*m ; i++){
            ans=min(ans , dis[i][d]);
        }
        cout << (ans==INF ? -1 : ans) << endl;


    }

}