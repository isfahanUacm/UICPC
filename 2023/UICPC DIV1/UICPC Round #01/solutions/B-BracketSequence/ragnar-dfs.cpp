#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
constexpr long long M = 1e9+7, OPEN=-1, CLOSE=-2;
using I = vector<long long>::iterator;
long long dfs(I* begin, bool op){
	assert(**begin == OPEN);
	long long v = op?0:1;
	for(++*begin; **begin!=CLOSE; ++*begin){
		long long x;
		if(**begin == OPEN){
			x = dfs(begin, !op);
		} else {
			x = **begin;
		}
		if(op) v = (v+x)%M; else v = v*x%M;
	}
	return v;
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
	cout << dfs(&it, true) << endl;
}
