#include <bits/stdc++.h>

using namespace std;

int main() {
  int S, N; cin >> S >> N;

  int pre;
  cin >> pre;
  int init = pre, ans = 0;
  for (int i = 1, cur; i < N; ++i) {
    cin >> cur;
    ans += (cur-pre-2)/2;
    pre = cur;
  }
  ans += (init+S-pre-2)/2;

  cout << ans << endl;

  return 0;
}
