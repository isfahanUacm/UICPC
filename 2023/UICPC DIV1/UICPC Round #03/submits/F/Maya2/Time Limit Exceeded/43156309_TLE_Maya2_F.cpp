#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+9;
vector<int> saf;
vector<int> saf1;
vector<vector<int>> safs;
vector<int> saf_t;

int main() {
	int n; cin >> n;
	int tmp;
	for(int i = 0; i < n; ++i){
		cin >> tmp;
		saf.push_back(tmp);
	}
	
	int m=0;
	bool flage = false;
	while(true) {
		flage = false;
		
		if(saf[0] < saf[1]) {
			saf_t.push_back(saf[0]);
			flage = true;
		}
		else saf1.push_back(saf[0]);
		for(int i = 1; i < saf.size()-1; ++i) {
			if(saf[i] < saf[i-1] || saf[i] < saf[i+1]) {
				saf_t.push_back(saf[i]);
				flage = true;
			}
			else {
				saf1.push_back(saf[i]);
			}
		}
		if(saf.size() > 1) {
			if(saf[saf.size()-1] < saf[saf.size()-2]) {
				flage = true;
				saf_t.push_back(saf[saf.size()-1]);
			}
			else saf1.push_back(saf[saf.size()-1]);
		}
		saf = saf1;
		saf1.clear();
	
		if(!flage) break;
		safs.push_back(saf_t);
		saf_t.clear();
	}

	cout << safs.size() << endl;
	for(auto i : safs) {
		for(auto j : i) {
			cout << j << ' ';
		}
		cout << endl;
	}
	for(auto i : saf) 
		cout << i << ' ';

	return 0;
}
