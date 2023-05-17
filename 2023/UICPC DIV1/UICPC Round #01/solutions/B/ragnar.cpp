#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

constexpr long long M = 1e9+7;

int main(){
	int n; cin >> n;
	string s;
	vector<long long> v{0};
	while(cin >> s){
		if(s == "("){
			v.push_back(v.size()%2 == 1 ? 1 : 0);
		} else {
			if(s != ")") v.push_back(stoll(s));
			auto x = v.back();
			v.pop_back();
			if(v.size() % 2 == 1) v.back() += x;
			else v.back() *= x;
			v.back() %= M;
		}
	}
	assert(v.size() == 1);
	cout << v[0] << endl;
}
