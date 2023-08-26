// [BAPC'12] Chess competition
// by: Jan Kuipers
// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <vector>

using namespace std;

vector<int> m,u;
vector<vector<int> > c;

bool match (int n) {

  if (u[n]) return false;
  u[n] = true;

  for (int i=0; i<c[n].size(); i++) {
    int x = c[n][i];
    if (m[x]==-1 || match(m[x])) {
      m[x] = n;
      return true;
    }
  }

  return false;
}

int main () {

  int runs;
  cin >> runs;

  while (runs--) {

    int n;
    cin >> n;
    vector<string> t_orig(n);
    for (int i=0; i<n; i++)
      cin >> t_orig[i];

    bool first = true;

    for (int player=0; player<n; player++) {

      bool ok = true;
      vector<string> t(t_orig);

      int score = 0;

      for (int i=0; i<n; i++) {
        if (t[player][i] == '.') {
          t[player][i] = '1';
          t[i][player] = '0';
        }
        if (t[player][i] == '1') score+=2;
        if (t[player][i] == 'd') score+=1;
      }

      vector<vector<int> > num(n, vector<int>(n, -1));
      int num_matches=0;
      for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
          if (t[i][j] == '.')
            num[i][j] = num_matches++;

      c = vector<vector<int> >(num_matches);

      int num_wins=0;
      for (int i=0; i<n; i++) {
        int max_win = score;
        for (int j=0; j<n; j++) {
          if (t[i][j] == '1') max_win-=2;
          if (t[i][j] == 'd') max_win-=1;
        }
        if (max_win < 0) ok = false;

        for (int j=0; j<n; j++)
          if (t[i][j] == '.')
            for (int k=0; k<max_win; k++) {
              c[num[i][j]].push_back(num_wins + k);
              c[num[j][i]].push_back(num_wins + k);
            }
        num_wins += max_win;
      }

      if (!ok) continue;

      m = vector<int>(num_wins, -1);

      for (int i=0; i<num_matches; i++) {
        u = vector<int>(num_matches, 0);
        if (!match(i)) {
          ok = false;
          break;
        }
      }

      if (ok) {
        if (!first) cout << " ";
        first = false;
        cout << player + 1;
      }
    }

    cout << endl;
  }

  return 0;
}
