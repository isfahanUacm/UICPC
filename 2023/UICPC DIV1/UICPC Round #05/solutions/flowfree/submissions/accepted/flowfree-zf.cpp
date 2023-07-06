#include <iostream>

using namespace std;

bool solve(int, int);

char g[4][5];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

bool extend(int r, int c, char end) {
  if (r < 0 || r >= 4 || c < 0 || c >= 4) return false;

  if (g[r][c] != 'W' && g[r][c] != end) return false;

  // cout << "extending: " << r << ' ' << c << ' ' << ' ' << end << endl;

  if (g[r][c] == 'W') {
    g[r][c] = '.';
    for (int i = 0; i < 4; ++i)
      if (extend(r+dr[i], c+dc[i], end))
        return true;
    g[r][c] = 'W';
  }
  else {
    g[r][c] = '.';
    if (solve(0, 0)) return true;
    g[r][c] = end;
  }

  return false;
}

bool tryPath(int r, int c) {
  // cout << "Trying path: " << r << ' ' << c << endl;
  char end = g[r][c];
  g[r][c] = '.';
  for (int i = 0; i < 4; ++i)
    if (extend(r+dr[i], c+dc[i], end))
      return true;
  g[r][c] = end;
  return false;
}

bool solve(int r, int c) {
  // cout << "Solving: " << r << ' ' << c << endl;

  if (c == 4)
    return solve(r+1, 0);

  if (r == 4) {
    for (auto x : g)
      for (int j = 0; j < 4; ++j)
        if (x[j] == 'W')
          return false;
    return true;
  }

  if (g[r][c] == 'W' || g[r][c] == '.')
    return solve(r, c+1);

  return tryPath(r, c);
}

int main() {
  for (auto r : g) cin >> r;

  cout << (solve(0, 0)?"solvable":"not solvable") << endl;

  return 0;
}
