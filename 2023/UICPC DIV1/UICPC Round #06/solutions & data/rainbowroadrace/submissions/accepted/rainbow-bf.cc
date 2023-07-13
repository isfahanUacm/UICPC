#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,ll> pll;
typedef pair<int,int> pii;


vector< vector< pair<pll, int> > > V;
map<char, int> C = { {'R', 0}, {'O', 1}, {'Y', 2}, {'G', 3},
		     {'B', 4}, {'I', 5}, {'V', 6}};

int main(){
   int n,m; cin >> n >> m; V.resize(n);
   for(int i = 0; i < m; i++){
      int u,v; ll d; char c;
      cin >> u >> v >> d >> c;
      V[u-1].emplace_back( make_pair(v-1, d), C[c]);
      V[v-1].emplace_back( make_pair(u-1, d), C[c]);
   }
   map<pii, ll> M;
   priority_queue<pair<ll,pii>,vector<pair<ll,pii>>,greater<pair<ll,pii>>> PQ;
   PQ.push( make_pair(0, make_pair(0,0)) );
   while(!PQ.empty()){
      pii cur = PQ.top().second; ll d = PQ.top().first; PQ.pop();
      if(M.find(cur) != M.end()) continue;
      M[cur] = d;
      for(auto x : V[cur.first]){
	 PQ.push( make_pair(M[cur] + x.first.second,
			    make_pair(x.first.first,
				      cur.second | (1 << x.second))));
      }
   }
   cout << M[make_pair(0, (1 << 7)-1)] << endl;
   return 0;
}
