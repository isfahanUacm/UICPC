#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
#include <string>
#define FOR(i,a,b) for(int i=1;i<=b;i++)
#define nei(node)  nodes[node].nei
using namespace std;
const int MAX = 1e5+100;

int arr[MAX];
vector<int> lt;
struct Node {
	Node(int id=-1) {
		this->id = id;
		this->time = 0;
	}
	int time;
	int id;
	vector<pair<int,int>> nei;
	int _min=-1;
};
Node nodes[MAX];


int binary_serach(int num) {
	int start = 0;
	int end = lt.size()-1;
	int ans = -1;
	while (start <= end)
	{
		int mid = (start + end) / 2;

		// Move to right side if target is
		// greater.
		if (lt[mid] <= num)
			start = mid + 1;

		// Move left side.
		else
		{
			ans = mid;
			end = mid - 1;
		}
	}
	return ans;
}
void dfs(int node) {
	int _min = -1;
	for (const auto& child : nei(node)) {
		if (_min == -1) {
			_min = child.second;
		}
		else {
			_min = min(_min, child.second);
		}
	}
	for (const auto& child : nei(node)) {
		nodes[child.first].time = nodes[node].time + _min + (child.second - _min) * 2;
		dfs(child.first);
	}
	if (nodes[node].nei.size() == 0) {
		lt.push_back(nodes[node].time);
	}
}
void solve() {
	int v;
	cin >> v;
	for (int i = 0; i < v; i++) {
		nodes[i].nei.clear();
	}
	for (int i = 1; i < v; i++) {
		int node, w;
		cin >> node >> w;
		nodes[node-1].nei.push_back({ i, w });
	}
	int q;
	cin >> q;

	for(int i=0;i<q;i++){
		cin >> arr[i];
		
	}
	dfs(0);
	string s;
	for (int i = 0; i < q; i++) {
		int res = binary_serach(arr[i]);
		if (res == -1) {
			if (lt[0] >= arr[i])
				s += "0\n";
			else
				s += to_string(lt.size()) + "\n";

		}
		else {
			s += to_string(res) + "\n";

		}
	}
	cout << s;
	


}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < MAX; i++) {
		nodes[i] = Node(i);
	}
	
	int t;
	cin >> t;

	while (t--) {
		solve();
	}

}
