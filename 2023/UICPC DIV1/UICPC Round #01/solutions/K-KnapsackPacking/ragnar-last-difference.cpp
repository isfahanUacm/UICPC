#include <iostream>
#include <cassert>
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
		auto v = *prev(s.end()) - *prev(prev(s.end()));
		ans.push_back(v);
		int s0 = s.size();
		for(auto j = begin(s); j != end(s); ++j){
			auto x = *j;
			auto it = prev(s.upper_bound(x+v));
			if(*it != x+v || it == j){
				cout << "impossible" << endl;
				return 0;
			}
			s.erase(it);
		}
		int s1 = s.size();
		assert(2*s1 == s0);
	}
	if(s.size() != 1 || *s.begin() != 0){
		cout << "impossible\n";
		return 0;
	}
	for(auto x : ans)
		cout << x << endl;
}
