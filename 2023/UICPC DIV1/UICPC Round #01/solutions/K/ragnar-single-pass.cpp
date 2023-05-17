#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	long long n; cin >> n;
	long long p = 1ll<<n;
	vector<int> s(p), cur{0};
	cur.reserve(p);
	for(auto&x : s) cin >> x;
	sort(begin(s), end(s));

	vector<int> ans;
	auto it = cur.begin();
	for(auto x : s){
		if(it != cur.end() && x == *it){
			++it;
			continue;
		}
		if(ans.size()==n || (it != cur.end() && *it < x)){
			cout << "impossible\n";
			return 0;
		}
		// Add x to the answer.
		ans.push_back(x);
		cur.reserve(2*cur.size());
		for(auto y : cur)
			cur.push_back(y+x);
		sort(begin(cur), end(cur));
		assert(*it == x);
		++it;
	}
	for(auto x : ans)
		cout << x << endl;
}
