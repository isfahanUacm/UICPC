#include <bits/stdc++.h>
using namespace std;

vector<vector<long long> > DP;
int n, m, k, r;
vector<int> L;
vector<pair<int,int> > C;

long long f(int seg, int l){
  if(seg == n) return (l == 0 ? 0 : LLONG_MAX/2);
  long long& x = DP[seg][l];
  if(x >= 0) return x;
  
  x = LLONG_MAX/2;
  for(int i=0;i<m;i++)
    if( abs(l-i) * k <= L[seg] ){
      long long curr = f(seg+1, i) + L[seg] +
	abs(l-i) * r + C[seg].first + C[seg].second * (i+1);
      x = min(x, curr);
    }
  
  return x;
}

int main(){
  cin >> n >> m >> k >> r;
  
  L.resize(n);
  for(auto& x : L) cin >> x;
  
  C.resize(n-1);
  for(auto& x : C) cin >> x.first >> x.second;
  C.emplace_back(0,0); // Make life easier...
  
  DP.assign(n+1, vector<long long>(m+1, -1));
  
  cout << f(0,0) << endl;
}
