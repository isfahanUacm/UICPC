// [BAPC'12] Hot dogs in Manhattan
// by: Jan Kuipers
// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <vector>

using namespace std;

const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = {  0, 0,-1, 1 };

int main () {

  int runs;
  cin >> runs;

  while (runs--) {

    int n,Y,X;
    cin >> n >> X >> Y;

    vector<int> sx(n),sy(n);
    for (int i=0; i<n; i++)
      cin >> sx[i] >> sy[i];

    int res = 0;

    for (int flip=0; flip<=1; flip++) {

      vector<vector<int> > u(X, vector<int>(Y, 0));

      int dist = 0;

      vector<pair<int,int> > p;
      for (int i=0; i<n; i++)
        p.push_back(make_pair(sx[i],sy[i]));

      vector<pair<int,int> > allp;
      for (int d=0; d<=X+Y; d++)
        for (int x=0; x<=d; x++) {
          int y = d-x;
          if (x>=0 && x<X && y>=0 && y<Y)
            allp.push_back(make_pair(x,y));
        }

      int i1=0, i2=allp.size()-1;

      while (true) {

        vector<pair<int,int> > newp;

        for (int i=0; i<p.size(); i++) {
          int x = p[i].first;
          int y = p[i].second;
          if (u[x][y]) continue;
          u[x][y] = 1;

          for (int d=0; d<4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx<0 || nx>=X || ny<0 || ny>=Y) continue;
            newp.push_back(make_pair(nx,ny));
          }
        }

        while (i1<allp.size() && u[allp[i1].first][allp[i1].second]) i1++;
        if (i1==allp.size()) break;

        while (i2>=0 && u[allp[i2].first][allp[i2].second]) i2--;

        if (allp[i2].first + allp[i2].second - allp[i1].first - allp[i1].second <= dist) break;

        dist++;

        p = newp;
      }

      res = max(res,dist);

      for (int i=0; i<n; i++)
        sx[i] = X-1-sx[i];
    }

    cout << res << endl;
  }

  return 0;
}
