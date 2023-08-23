// l a s h v

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define endll '\n'
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fori(x, u) for (int i = x; i < u; ++i)
#define forj(x, u) for (int j = x; j < u; ++j)
#define sortv(a) sort(a.begin(), a.end())
#define ES cout << "YES\n"
#define NO cout << "NO\n"
#define sep() cout << "------------------------------------------------------\n"
#define print_map(mp) for (auto x : mp) cout << x.first << ": " << x.second << endll
#define print_vec(vc) for (auto x : vc) cout << x << ' '; cout << endll
// lower_bound -> greater than or equal
// upper_bound -> greater than
const int maxn = 2e5+9;

void solve() {
	int n;
	cin >> n;
	vector<pii> arr(n);
	fori (0, n) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end(), greater<pii>());

  map<int, vector<int>> mp;
  for (auto x : arr) {
    mp[x.first].push_back(x.second);
  }

	multiset<int> st;
  for (auto x = mp.rbegin(); x != mp.rend(); ++x) {
    vector<int> tmp;
    for (auto u : x->second) {
        auto it = st.upper_bound(u);
        if (it == st.end()) tmp.push_back(u);
        else {
            st.erase(it);
            tmp.push_back(u);
        }
      }
      for (auto u : tmp) st.insert(u);
  }

  cout << st.size() << endll;
}

int main() {
    ios::sync_with_stdio(false);
		cin.tie(nullptr);
    //cout << fixed << setprecision(9);
    int T; cin >> T; while (T--)
    solve();

    return 0;
}