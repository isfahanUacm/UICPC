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

int main() {
    int n;
    cin >> n;
    int x = -1;
    int y = -1;
    bool won = 0;
    rep(c1,0,n){
        int a, b;
        cin >> a >> b;
        b = -b;
        if((a+b)%4 == 0 || (a+b)%4 == 3){
            swap(a, b);
        }
        if(a == x && b == y)continue;

        bool fail = 0;

        if(max(a, b) > 11 || won || (a == 11 && b == 11))fail = 1;

        if(a < x || b < y || fail){
            cout << "error " << c1+1 << "\n";
            return 0;
        }

        if(max(a, b) == 11)won = 1;

        x = a;
        y = b;
    }
    cout << "ok\n";
    return 0;
}
