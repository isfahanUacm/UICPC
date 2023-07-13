#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 255;
const ll inf = 1e14;
int m; ll k,r;
vector<ll> len;
vector<ll> curv;

ll DP[MAX][MAX];
bool seen[MAX][MAX];

ll solve(int sa, int la){
   ll & x = DP[sa][la];
   if(seen[sa][la]) return x;
   ll best = inf;
   for(int j = max((ll)0, la - len[sa]/k); j <= min((ll)m-1, la + len[sa]/k); j++){
      ll diff = abs(la-j);
      best = min(best, diff*r + curv[sa]*(j+1) + solve(sa+1, j));
   }
   seen[sa][la] = true;
   return x = best;
}

int main(){
   for(int i = 0; i < MAX; i++)
      for(int j = 0; j < MAX; j++)
	 seen[i][j] = false;
   int n; cin >> n >> m >> k >> r;
   len.resize(n); curv.resize(n);
   for(int i = 0; i < m; i++){
      DP[n][i] = inf;
      seen[n][i] = true;
   }
   DP[n][0] = 0;
   ll ans = 0;

   for(auto & x : len){
      cin >> x;
      ans += x;
   }
   for(int i = 0; i < n-1; i++){
      ll l; cin >> l >> curv[i];
      ans += l;
   }
   curv[n-1] = 0;
   ans += solve(0, 0);
   cout << ans << endl;
   return 0;
}

