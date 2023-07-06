#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  vector<int> t(n), l(m);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> l[i];
  }
  sort(t.rbegin(), t.rend());
  sort(l.rbegin(), l.rend());

  int t_i = 0, l_i = 0;
  for ( ; l_i < m; l_i++) {
    for ( ; t_i < n && t[t_i] > l[l_i]; t_i++)
      ;
    if (t_i++ >= n) break;
  }
  cout << l_i << endl;

  return 0;
}
