#include <bits/stdc++.h>
using namespace std;

int f(int idx, int wins_left, vector<vector<int>>& DP, const vector<int>& A) {
  if(idx == DP.size()) return 0;

  int& x = DP[idx][wins_left];
  if(x >= 0) return x;

  x = f(idx + 1, wins_left, DP, A) + A[idx] / 2;
  if(wins_left)
    x = max(x, f(idx + 1, wins_left - 1, DP, A) + A[idx]);
  return x;
}

int do_case() {
  int n; cin >> n;
  vector<int> A(n);
  for (auto& x : A) cin >> x;

  vector<vector<int>> DP(n, vector<int>(n/2 + 1, -1));

  return f(0, n/2, DP, A);
}

int main() {
  cout << do_case() << endl;
}
