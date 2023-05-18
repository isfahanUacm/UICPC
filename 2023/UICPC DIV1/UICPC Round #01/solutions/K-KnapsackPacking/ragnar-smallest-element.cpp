#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
	long long n; cin >> n;
	long long p = 1ll<<n;
	multiset<int> s;
	while(p--){ int x; cin >> x; s.insert(x); }
	vector<int> ans;
	while(n--){
		auto v = *next(s.begin());
		ans.push_back(v);
		for(auto j = begin(s); j != end(s); ++j){
			auto x = *j;
			auto it = prev(s.upper_bound(x+v));
			if(it == j || *it != x+v){
				cout << "impossible" << endl;
				return 0;
			}
			s.erase(it);
		}
	}
	for(auto x : ans)
		cout << x << endl;
}
