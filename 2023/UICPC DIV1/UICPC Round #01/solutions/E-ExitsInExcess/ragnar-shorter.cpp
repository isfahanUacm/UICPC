#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
int main(){
	long long n, m;
	cin >> n >> m;
	vector<int> inc, dec;
	for(int i = 1; i <= m; ++i){
		int u,v; cin >> u >> v;
		if(v>u) inc.push_back(i);
		else dec.push_back(i);
	}
	if(inc.size() > dec.size()) swap(inc, dec);
	cout << inc.size() << endl;
	for(auto x : inc) cout << x << endl;
}
