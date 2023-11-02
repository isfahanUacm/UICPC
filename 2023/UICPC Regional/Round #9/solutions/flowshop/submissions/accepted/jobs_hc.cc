#include <bits/stdc++.h>

using namespace std;

int n, m;
int p[1000][1000];
int done[1000] = {0};

int main()
{
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> p[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    int curr_time = 0;

    for (int j = 0; j < m; j++) {
      curr_time = done[j] = max(curr_time, done[j]) + p[i][j];
    }

    if (i) cout << ' ';
    cout << curr_time;
  }
  cout << endl;
  return 0;
}
