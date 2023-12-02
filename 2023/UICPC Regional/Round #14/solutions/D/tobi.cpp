// @EXPECTED_RESULTS@: CORRECT
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[105];
int numCases, numStores, x, y;
vector<pair<int, int> > stores;

bool happy(int cur) {
	if (cur == numStores - 1) return true;
	if (visited[cur]) return false;
	visited[cur] = true;
	
	for (int i = 1; i < numStores; i++) {
		if (i != cur && abs(stores[cur].first - stores[i].first) + abs(stores[cur].second - stores[i].second) <= 1000 && happy(i)) return true;
	}

	return false;
}

int main() {
	cin >> numCases;

	while (numCases --> 0) {
		cin >> numStores;
		stores.clear();
		numStores += 2;
		for (int i = 0; i < numStores; i++) {
			visited[i] = false;
			cin >> x >> y;
			stores.push_back(make_pair(x,y));
		}
		cout << (happy(0) ? "happy" : "sad") << endl;
	}

	return 0;
}
