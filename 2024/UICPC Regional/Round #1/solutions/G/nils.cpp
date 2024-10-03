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

const int MAXN = 5002;

vector<double> P;
double DP[2*MAXN][2] = {0};
int n, k;

int main() {
    
    cin >> n >> k;
    rep(c1,0,n){
        double p;
        cin >> p;
        P.push_back(p);
    }
    sort(all(P));
    reverse(all(P));
    double ans = 0.0;
    DP[MAXN][1] = 1.0;
    rep(c1,0,n){
        double sum = 0.0;
        for(int score = -n; score <= n; score++){
            int index = MAXN+score;
            DP[index][c1%2] = DP[index-1][(c1+1)%2] * P[c1] + DP[index+1][(c1+1)%2] * (1.0-P[c1]);
            if(score >= k)sum += DP[index][c1%2];
        }
        ans = max(ans, sum);
    }
    cout << setprecision(15) << fixed << ans << "\n";

    return 0;
}
