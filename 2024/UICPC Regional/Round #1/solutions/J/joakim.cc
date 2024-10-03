#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;


int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
string dir[] = {"left", "up", "right", "down"};


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin>>n;
    int x = 0, y = 0;
    cin>>x>>y;
    int xt=0 ,yt=0;
    cin>>xt>>yt;
    x -= xt; y -= yt;
    set<pii> pts;
    rep(i,0,n) {
        int a,b;
        cin>>a>>b;
        pts.emplace(a-xt,b-yt);
    }
    auto go = [&](int t){
        x += dx[t], y += dy[t];
        cout << dir[t] << endl;
        if(pts.count(pii(x,y))) {
            int xx = x, yy = y;
            while(pts.count(pii(xx,yy))) xx += dx[t], yy += dy[t];
            pts.erase(pii(x,y));
            pts.emplace(xx,yy);
            pts.erase(pii(0,0));
        }
    };
    auto R = [&](){ go(2); };
    auto L = [&](){ go(0); };
    auto U = [&](){ go(1); };
    auto D = [&](){ go(3); };

    while(x > 0) L();
    while(x < 0) R();
    while(y > 0) D();
    while(y < 0) U();

    while(sz(pts)) {
        assert(x == 0 && y == 0);

        int target_x = pts.begin()->first;
        int target_y = pts.begin()->second;

        if(target_x != 0) {
            while(y > target_y+1) D();
            while(y < target_y+1) U();
            while(x > target_x) L();
            while(x < target_x) R();
            if(target_x > 0) {
                R(); D();
                while(x > 1) L();
            }
            if(target_x < 0) {
                L(); D();
                while(x < -1) R();
            }
        }
        else if(target_y != 0) {
            R();
            while(y > target_y) D();
            while(y < target_y) U();
            if(target_y > 0) { U(); L(); }
            if(target_y < 0) { D(); L(); }
        }

        while(y > 0) D();
        while(y < 0) U();
        while(x > 0) L();
        while(x < 0) R();
    }
}
