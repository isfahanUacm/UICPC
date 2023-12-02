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

int n,m,s,d;
vi ind, cold, ans;

bool comp(int i, int j){
    return cold[i] < cold[j];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,s,d;
    cin >> n >> m >> s >> d;
    rep(c1,0,s){
        int a;
        cin >> a;
        cold.push_back(a);
        ind.push_back(c1);
        ans.push_back(0);
    }
    sort(all(ind),comp);
    int visible = 0;

    rep(c1,0,s){
        int i = ind[c1];
        if(n == 0){
            visible += cold[i];
            continue;
        }
        ans[i] = min(n, d - cold[i]);
        n = max(0, n - d + cold[i]);
    }

    if(visible >= m){
        rep(c1,0,s){
            cout << ans[c1] << " ";
        }cout << "\n";
    }
    else{
        cout << "impossible\n";
    }

    return 0;
}

