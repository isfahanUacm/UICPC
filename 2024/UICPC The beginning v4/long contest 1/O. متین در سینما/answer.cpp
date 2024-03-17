#include "bits/stdc++.h"
#ifndef LOCAL
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define LINE
#else
#define fastio
#define LINE cerr << "------------------------" << nl;
#endif

#define nl '\n'
#define pb push_back
#define arr array
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long; using ld = long double; using str = string;
const int N = 1e3+5;
int r, c, a[N][N];
void solve() {
	cin >> r >> c;
	char tmp;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			cin >> tmp;
			if (tmp=='s') {
				a[i][j] = 1;
			} else if (tmp == 'n') {
				a[i][j] = 2;
			} else if (tmp == 't') {
				a[i][j] = 3;
			} else {
				a[i][j] = 0;
			}
		}
	}
	int s, n, t;
	cin >> s >> n >> t;
	for (int j=0; j<c; j++) {
		int lst = -1;
		for (int i=0; i<r; i++) {
			if (a[i][j]) {
				if (lst==-1) lst = i;
				else if (a[lst][j] < a[i][j]) {
					cout << "Let's go to the park" << nl;
					return;
				} else {
					lst = i;
				}
			}
		}
	}
	vector<int> tn, ns, ts;
	arr<int, 4> first[c], last[c];
	for (int j=0; j<c; j++) {
		for (int i=0; i<4; i++) first[j][i] = -1, last[j][i] = -1;
		for (int i=0; i<r; i++) {
			if (first[j][a[i][j]]==-1) {
				first[j][a[i][j]] = i;
			}
		}
		for (int i=r-1; ~i; i--) {
			if (last[j][a[i][j]]==-1) {
				last[j][a[i][j]] = i;
			}
		}

		if (~last[j][3])
		for (int i=0; i<last[j][3]; i++) {
			if (t && !a[i][j]) {
				a[i][j] = 3;
				t--;
			}
		}
		if (~first[j][1])
		for (int i=r-1; i>=first[j][1]+1; i--) {
			if (s && !a[i][j]) {
				a[i][j] = 1;
				s--;
			}
		}
		if (~first[j][2])
		for (int i=first[j][2]; i<last[j][2]; i++) {
			if (n && !a[i][j]) {
				a[i][j] = 2;
				n--;
			}
		} 
	}

	auto sets = [&] () {
		// set s
		for (int j=0; j<c; j++) {
			int beg, end;
			if (~first[j][1]) {
				end = first[j][1];
			} else end = r;

			if (~first[j][2]) beg = last[j][2];
			else if (~first[j][3]) beg = last[j][3];
			else beg = 0;

			for (int i=end-1; i>=beg; i--) {
				if (s && !a[i][j]) {
					a[i][j] = 1;
					s--;
				}
			}
		}
	};
	auto sett = [&] () {
		// set t
		for (int j=0; j<c; j++) {
			int beg, end;
			if (~first[j][3]) {
				beg = last[j][3]+1;
			} else beg = 0;

			if (~first[j][2]) end = first[j][2];
			else if (~first[j][1]) end = first[j][1];
			else end = r;

			for (int i=beg; i<end; i++) {
				if (t && !a[i][j]) {
					a[i][j] = 3;
					t--;
				}
			}
		}
	};
	if (s > t) {
		sets();
		sett();
	} else {
		sett();
		sets();
	}
	// set n
	for (int j=0; j<c; j++) {
		int beg, end;
		if (~first[j][3]) {
			beg = last[j][3]+1;
		} else {
			beg = 0;
		}

		if (~first[j][1]) {
			end = first[j][1];
		} else {
			end = r;
		}
		for (int i=beg; i<end; i++) {
			if (n && !a[i][j]) {
				a[i][j] = 2;
				n--;
			}
		}
	}
	if (s+n+t > 0) {
		cout << "Let's go to the park" << nl;
		return;
	}
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (a[i][j]==1) {
				cout << 's';
			} else if (a[i][j]==2) {
				cout << 'n';
			} else if (a[i][j]==3) {
				cout << 't';
			} else {
				cout << '#';
			}
		}
		cout << nl;
	}
	
}

int main() {
  int T = 1;
//cin >> T;
  while (T--) {
    solve();
	LINE
  }
    return 0;
}

