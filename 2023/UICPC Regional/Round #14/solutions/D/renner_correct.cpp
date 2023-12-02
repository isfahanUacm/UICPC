// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <cstring>

#define abs(a) ((a > 0) ? (a) : -(a))

using namespace std;

#define MAX_STORES  101
#define BPM 50
#define B   20

int  x[MAX_STORES + 2];
int  y[MAX_STORES + 2];
bool e[MAX_STORES + 2][MAX_STORES + 2];
bool vis[MAX_STORES + 2];
int n;

bool go(int p) {
  if (p == n + 1) return true;
  vis[p] = true;

  for (int i = 1; i <= n + 1; i++) {
    if (e[p][i] && !vis[i] && go(i)) return true;
  }

  //vis[p] = false;  // NOTE no backtracking required (this line triggers a time limit)
  return false;
}

int main() {
  int C;
  cin >> C;
  while (C--) {
    memset(e,   0, sizeof(e));
    memset(vis, 0, sizeof(vis));

    cin >> n;
    for (int i = 0; i < n + 2; i++) {
      cin >> x[i] >> y[i];

      for (int j = 0; j < i; j++) {
        if (abs(x[i]-x[j]) + abs(y[i]-y[j]) <= B*BPM) {
          e[i][j] = e[j][i] = 1;
        }
      }
    }

    cout << (go(0) ? "happy" : "sad") << endl;
  }

  return 0;
}
