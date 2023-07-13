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
      v--; u--;
      V[u].emplace_back( make_pair(v,d), C[c]);
      V[v].emplace_back( make_pair(u,d), C[c]);
   }

   vector<ll> M(n << 7, -1);
   
   priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> PQ;
   PQ.push( make_pair(0, 0) );
   while(!PQ.empty()){
     int cur = PQ.top().second; ll d = PQ.top().first; PQ.pop();
     if(M[cur] >= 0) continue;
     M[cur] = d;
     int my_colours = cur % (1 << 7);
     int my_vertex = cur >> 7;
     for(auto x : V[my_vertex])
       PQ.emplace( M[cur] + x.first.second,
		   (x.first.first << 7) | my_colours | (1 << x.second));
   }
   cout << M[(1 << 7)-1] << endl;
}
