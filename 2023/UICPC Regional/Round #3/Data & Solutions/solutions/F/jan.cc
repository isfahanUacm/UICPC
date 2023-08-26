// [BAPC'12] Fire
// by: Jan Kuipers
// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int dy[4] = { 1,-1, 0, 0 };
const int dx[4] = { 0, 0,-1, 1 };

int main () {

  int runs;
  cin >> runs;

  while (runs--) {

    int Y,X;
    cin >> X >> Y;

    vector<string> m(Y);
    for (int y=0; y<Y; y++)
      cin >> m[y];

    vector<vector<int> > dist(Y, vector<int>(X, -1));

    queue<int> q;
    for (int y=0; y<Y; y++)
      for (int x=0; x<X; x++)
        if (m[y][x]=='@') {
          q.push(0);
          q.push(y);
          q.push(x);
          dist[y][x] = 0;
        }

    for (int y=0; y<Y; y++)
      for (int x=0; x<X; x++)
        if (m[y][x]=='*') {
          q.push(1);
          q.push(y);
          q.push(x);
        }

    int res = -1;

    while (!q.empty()) {
      int t = q.front(); q.pop();
      int y = q.front(); q.pop();
      int x = q.front(); q.pop();

      if (t==0 && m[y][x]=='*') continue;

      if (t==0 && (y==0 || y==Y-1 || x==0 || x==X-1)) {
        res = dist[y][x]+1;
        break;
      }

      for (int d=0; d<4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny<0 || ny>=Y || nx<0 || nx>=X) continue;

        if (m[ny][nx]=='#' || m[ny][nx]=='*') continue;

        if (t==0 && dist[ny][nx]==-1) {
          dist[ny][nx] = dist[y][x] + 1;
          q.push(0);
          q.push(ny);
          q.push(nx);
        }

        if (t==1) {
          m[ny][nx] = '*';
          q.push(1);
          q.push(ny);
          q.push(nx);
        }
      }
    }

    if (res == -1)
      cout << "IMPOSSIBLE" << endl;
    else
      cout << res << endl;
  }

  return 0;
}
