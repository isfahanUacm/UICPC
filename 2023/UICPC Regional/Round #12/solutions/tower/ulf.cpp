#include <iostream>
using namespace std;

#include <vector>
#include <set>
#include <map>
typedef pair<int, int> pii;

int main() {
	int n;
	cin >> n;
	multimap<int, int> blocks;
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		int s, t;
		cin >> s >> t;
		blocks.insert(pii(-s,-t));
		blocks.insert(pii(-t,-s));
		res += s + t;
	}
	while (!blocks.empty()) {
		int start = blocks.begin()->first;
		int e = 0;
		vector<int> s(1, start);
		set<int> visited;
		while (!s.empty()) {
			int a = s.back();
			s.pop_back();
			if (visited.count(a)) {
				continue;
			}
			res += a;
			visited.insert(a);
			multimap<int, int>::iterator it;
			while((it = blocks.find(a)) != blocks.end()) {
				s.push_back(it->second);
				blocks.erase(it);
				e += 1;
			}
		}
		if (visited.size()*2 != e)
			res -= start;
	}
	cout << res << endl;
}