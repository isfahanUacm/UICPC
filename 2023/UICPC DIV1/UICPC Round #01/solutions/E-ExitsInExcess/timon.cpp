#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> ids[2];
	for (int id = 1, u, v; id <= m; ++id)
		cin >> u >> v,
		ids[u < v].push_back(id);

	int rem = (ids[0].size() < ids[1].size() ? 0 : 1);
	cout << ids[rem].size() << endl;
	for (int v : ids[rem]) cout << v << '\n';
	cout << flush;
}
