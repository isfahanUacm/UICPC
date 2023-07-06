#include <bits/stdc++.h>

using namespace std;

string grid[4];
string color = "RGBY";
int num_colors;

typedef pair<int,int> pii;
pii endpoint[4][2];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool trace(string grid[4], char col, int r, int c, int r2, int c2)
{
  bool result = false;
  
  grid[r][c] = 'X';
  if (r == r2 && c == c2) {
    bool good = true;
    for (int i = 0; i < 4 && true; i++) {
      good &= grid[i].find(col) == string::npos;
    }
    result = good;
    goto cleanup;
  }

  for (int d = 0; d < 4; d++) {
    int rr = r + dr[d], cc = c + dc[d];
    if (0 <= rr && rr < 4 && 0 <= cc && cc < 4 &&
	grid[rr][cc] == col) {
      if (trace(grid, col, rr, cc, r2, c2)) {
	result = true;
	goto cleanup;
      }
    }
  }

 cleanup:
  grid[r][c] = col;
  return result;
  
}

bool trace(string grid[4])
{
  for (int i = 0; i < num_colors; i++) {
    if (!trace(grid, color[i],
	       endpoint[i][0].first, endpoint[i][0].second,
	       endpoint[i][1].first, endpoint[i][1].second))
      return false;
  }
  return true;
}

bool solvable(string grid[4], int r = 0, int c = 0)
{
  if (r == 4) {
    return trace(grid);
  }
  if (c == 4) {
    return solvable(grid, r+1, 0);
  }
  if (grid[r][c] != 'W') {
    return solvable(grid, r, c+1);
  }

  for (int i = 0; i < num_colors; i++) {
    grid[r][c] = color[i];
    if (solvable(grid, r, c+1))
      return true;
  }
  grid[r][c] = 'W';
  return false;
}

int main()
{
  num_colors = 3;
  for (int i = 0; i < 4; i++) {
    cin >> grid[i];
    if (grid[i].find('Y') != string::npos) {
      num_colors = 4;
    }
  }

  for (int c = 0; c < num_colors; c++) {
    int e = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
	if (grid[i][j] == color[c]) {
	  endpoint[c][e++] = make_pair(i,j);
	}
      }
    }
  }
  
  cout << (solvable(grid) ? "solvable" : "not solvable") << endl;
  return 0;
}
