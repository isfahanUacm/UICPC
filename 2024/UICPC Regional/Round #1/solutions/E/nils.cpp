#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int MAXN = 3001;
int n,m;
vector<vi> C(MAXN, vi());

int cyc = MAXN;
ll ans = 0;

void bfs1(int i){
    vi dist(n, MAXN);
    dist[i] = 0;
    queue<int> Q;
    Q.push(i);
    while(!Q.empty()){
        int a = Q.front();
        Q.pop();
        trav(y, C[a]){
            if(dist[y] == MAXN){
                dist[y] = 1 + dist[a];
                Q.push(y);
            }
            else{
                if(dist[y] >= dist[a]){
                    cyc = min(cyc, dist[a] + dist[y] + 1);
                }
            }
        }
    }
}

void bfs2(int i){
    vi dist(n, MAXN);
    dist[i] = 0;
    queue<int> Q;
    Q.push(i);
    while(!Q.empty()){
        int a = Q.front();
        Q.pop();
        trav(y, C[a]){
            if(dist[y] == MAXN){
                dist[y] = 1 + dist[a];
                Q.push(y);
            }
        }
    }
    if(cyc%2 == 0){
        rep(c1,0,n){
            if(dist[c1] == cyc/2){
                ll res = 0;
                trav(y, C[c1]){
                    if(dist[y] == dist[c1]-1)res++;
                }
                ans += res*res-res;
            }
        }
    }
    else{
        rep(c1,0,n){
            if(dist[c1] == cyc/2){
                ll res = 0;
                trav(y, C[c1]){
                    if(dist[y] == dist[c1])res++;
                }
                ans += res;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    rep(c1,0,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }

    rep(c1,0,n){
        bfs1(c1);
    }
    rep(c1,0,n){
        bfs2(c1);
    }

    assert(ans % (2*cyc) == 0);
    ans /= (2*cyc);
    assert(ans > 0);
    cout << ans << "\n";

    return 0;
}
