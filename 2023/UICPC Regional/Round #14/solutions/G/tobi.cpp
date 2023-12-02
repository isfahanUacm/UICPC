// @EXPECTED_RESULTS@: CORRECT
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define add(a,b) ranges[cnt++] = make_pair(a,b)
typedef pair<int,int> pii;

pii ranges[200000];
int numCases, m, n, s, e;

int main() {
	cin >> numCases;
	while (numCases --> 0) {
		cin >> m >> n;
		int cnt = 0;
		FOR(i, 0, n) {
			cin >> s >> e;
			if (s <= e) {
				add(s, e);
				add(s+m, e+m);
			} else add(s, e+m);
		}
		if (n > m) {
			cout << "NO" << endl;
			continue;
		}
		sort(ranges + 0, ranges + cnt);

		int c = 0, curC = 0;
		multiset<int> active;
		bool success = true;
		while (c < 2*m) {
			if (active.empty()) {
				if (curC < cnt) c = ranges[curC].first;
				else break;
			}
			while (curC < cnt && c == ranges[curC].first) {
				active.insert(ranges[curC].second);
				curC++;
			}
			auto x = active.begin();
			int latest = *x;
			active.erase(x);
			if (!(c <= latest)) {
				success = false;
				break;
			}
			c++;
		}
		cout << (success ? "YES" : "NO") << endl;
	}
	return 0;
}
