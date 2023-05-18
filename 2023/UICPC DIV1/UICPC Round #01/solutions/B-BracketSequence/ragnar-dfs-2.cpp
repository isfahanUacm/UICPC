#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
constexpr long long M = 1e9+7, OPEN=-1, CLOSE=-2;
using I = vector<long long>::iterator;
pair<long long, long long> dfs(I& begin){
	assert(*begin == OPEN);
	long long v1 = 0, v2 = 1;
	for(++begin; *begin!=CLOSE; ++begin){
		long long x1=*begin, x2=*begin;
		if(*begin == OPEN){
			auto x = dfs(begin);
			x1 = x.first, x2 = x.second;
		}
		v1 = (v1+x2)%M, v2 = v2*x1%M;
	}
	assert(*begin == CLOSE);
	return {v1,v2};
}
int main(){
	int n; cin >> n;
	vector<long long> l;
	l.push_back(OPEN);
	for(int i = 0; i < n; ++i){
		string s; cin >> s;
		if(s == "(") l.push_back(OPEN);
		else if(s == ")") l.push_back(CLOSE);
		else l.push_back(stoll(s));
	}
	l.push_back(CLOSE);
	auto it = begin(l);
	cout << dfs(it).first << endl;
}
