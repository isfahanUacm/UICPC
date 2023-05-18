#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
int main(){
	long long n, m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> g(n);
	int inc = 0, dec = 0;
	for(int i = 1; i <= m; ++i){
		int u,v; cin >> u >> v;
		--u, --v;
		assert(u!=v);
		g[u].push_back({v,i});
		if(v > u) ++inc; else ++dec;
	}

	if(inc < dec){
		cout << inc << endl;
		for(int u = 0; u < n; ++u)
			for(auto e : g[u]){
				if(e.first > u)
					cout << e.second << endl;
			}
	} else {
		cout << dec << endl;
		for(int u = 0; u < n; ++u)
			for(auto e : g[u]){
				if(e.first < u)
					cout << e.second << endl;
			}
	}
}
