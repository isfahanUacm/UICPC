#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v1(n), v2(n);
  for (int& x : v1) cin >> x;
  for (int& x : v2) cin >> x;

  unordered_map<int, int> cnt;
  vector<int> ans;
  int off = 0;

  auto update = [&](int x, int d) {
    if (cnt[x] == 0) ++off;
    if ((cnt[x] += d) == 0) --off;
  };

  for (int i = 0; i < n-1; ++i) {
    update(v1[i], 1);
    update(v2[i], -1);
    if (off == 0) ans.push_back(i);
  }

  int ia = 0;
  for (int i = 0; i < n; ++i) {
    cout << v2[i] << (i+1==n?'\n':' ');
    if (ia < ans.size() && i == ans[ia]) {
      cout << "# ";
      ++ia;
    }
  }


  return 0;
}
