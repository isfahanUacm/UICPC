#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main() {
	int n; cin >> n;
	int t, lt;
	int cur_t = 0;
	bool on = false;
	for(int i = 0; i < n; ++i) {
		cin >> t;
	
		if(on) {
			cur_t += t - lt;	
		}
		lt = t;
		if(!on) on = true;
		else on = false;
	}

	if(on) cout << "still running";
	else cout << cur_t;
	
	return 0;
}
