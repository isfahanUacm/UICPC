#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
	int n, p, s, tmp;
	cin >> n >> p >> s;
	for(int j = 0; j < s; ++j) {
		cin >> tmp;
		int tt;
		bool t = false;
		for(int i = 0; i < tmp; ++i) {
			cin >> tt;
			if(tt == p) t = true;		
		}	
		if(t) cout << "KEEP" << endl;
		else cout << "REMOVE" << endl;
	}
	return 0;
}