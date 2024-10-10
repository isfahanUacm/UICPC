#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
typedef long long ll;
#define FOR(i,a,b) for(ll i=1;i<=b;i++)
#define nei(node)  nodes[node].nei
using namespace std;
const ll MAX = 1e5+100;

ll arr[MAX];
vector<ll> lt;
struct Node {
	Node(ll id=-1) {
		this->id = id;
		this->time = 0;
	}
	ll time;
	ll id;
	vector<pair<ll,ll>> nei;
	ll _min=-1;
};
Node nodes[MAX];


ll binary_serach(ll num) {
	ll start = 0;
	ll end = lt.size()-1;
	ll ans = -1;
	while (start <= end)
	{
		ll mid = (start + end) / 2;

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
void dfs(ll node) {
	ll _min = -1;
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
	ll v;
	cin >> v;
	for (ll i = 0; i < v; i++) {
		nodes[i].nei.clear();
	}
	for (ll i = 1; i < v; i++) {
		ll node, w;
		cin >> node >> w;
		nodes[node-1].nei.push_back({ i, w });
	}
	ll q;
	cin >> q;

	for(ll i=0;i<q;i++){
		cin >> arr[i];
		
	}
	dfs(0);
	sort(lt.begin(), lt.end());
	string s;
	for (ll i = 0; i < q; i++) {
		ll res = binary_serach(arr[i]);
		if (res == -1) {
			if (lt[0] > arr[i])
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

	for (ll i = 0; i < MAX; i++) {
		nodes[i] = Node(i);
	}
	
	ll t;
	cin >> t;

	while (t--) {
		solve();
	}

}
