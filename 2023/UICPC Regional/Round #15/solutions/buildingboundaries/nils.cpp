#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

struct pt{
    ll x,y;
};

ll T;
ll ans = 4e18 + 1;

vector<pt> P,Q,X;
vector<pt> pos;
vi ind;


void solve(int i){
    if(i == 3){
        for(int c1 = 0; c1 < 3; c1++){
            for(int c2 = c1+1; c2 < 3; c2++){
                if(X[c1].x > X[c2].x + Q[c2].x)continue;
                if(X[c2].x > X[c1].x + Q[c1].x)continue;
                if(X[c1].y > X[c2].y + Q[c2].y)continue;
                if(X[c2].y > X[c1].y + Q[c1].y)continue;
                return;
            }
        }
        ll maxx = 0;
        ll maxy = 0;
        rep(c1,0,3){
            maxx = max(maxx, Q[c1].x + X[c1].x + 1);
            maxy = max(maxy, Q[c1].y + X[c1].y + 1);
        }
        ans = min(ans, maxx * maxy);
        return;
    }
    rep(c1,0,sz(pos)){
        X[i] = pos[c1];
        pos.push_back({X[i].x, X[i].y + Q[i].y + 1});
        pos.push_back({X[i].x + Q[i].x + 1, X[i].y});
        solve(i+1);
        pos.pop_back();
        pos.pop_back();
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    rep(c1,0,3){P.push_back({0,0});}
    rep(c1,0,3){Q.push_back({0,0});}
    rep(c1,0,3){X.push_back({0,0});}

    cin >> T;
    rep(c4,0,T){
        rep(c1,0,3){
            cin >> P[c1].x >> P[c1].y;
            P[c1].x--;
            P[c1].y--;
        }
        ans = 4e18+1;
        rep(c1,0,8){
            vi ind(3);
            rep(c2,0,3){
                ind[c2] = c2;
            }
            rep(c2,0,6){
                rep(c3,0,3){
                    Q[c3] = P[ind[c3]];
                    if(((1 << c3) & c1) != 0){
                        swap(Q[c3].x, Q[c3].y);
                    }
                }
                pos.clear();
                pos.push_back({0,0});
                solve(0);
                next_permutation(all(ind));
            }
        }
        cout << ans << "\n";
    }

    return 0;
}

