#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;

vi stable_marriage(int n, int** m, int** w) {
  queue<int> q;
  vi at(n, 0), eng(n, -1), res(n, -1); vvi inv(n, vi(n));
  rep(i,0,n) rep(j,0,n) inv[i][w[i][j]] = j;
  rep(i,0,n) q.push(i);
  while (!q.empty()) {
    int curm = q.front(); q.pop();
    for (int &i = at[curm]; i < n; i++) {
      int curw = m[curm][i];
      if (eng[curw] == -1) { }
      else if (inv[curw][curm] < inv[curw][eng[curw]])
        q.push(eng[curw]);
      else continue;
      res[eng[curw] = curm] = curw, ++i; break; } }
  return res; }

int p[1010][1010],
    q[1010][1010];

int startedPlaying[1010][1010],
    totalPlaytime[1010][1010];

int main() {
    int n, m;
    cin >> n >> m;

    if (n > m) {
        cout << "impossible" << endl;
        return 0;
    }

    int at = 2000000000;
    rep(i,0,n) {
        rep(j,0,m) {
            startedPlaying[i][j] = at--;
        }
    }

    int d, e;
    cin >> d >> e;

    vi cur(n, -1);
    rep(i,0,e) {
        int s, k, t;
        cin >> s >> k >> t;
        k--, t--;
        if (cur[k] != -1) {
            totalPlaytime[k][cur[k]] += s;
        }
        cur[k] = t;
        if (t != -1) {
            totalPlaytime[k][t] -= s;
            if (startedPlaying[k][t] > d) {
                startedPlaying[k][t] = s;
            }
        }
    }
    rep(i,0,n) {
        if (cur[i] != -1) {
            totalPlaytime[i][cur[i]] += d;
        }
    }

    rep(i,0,n) {
        vii arr;
        rep(j,0,m) {
            arr.push_back(ii(startedPlaying[i][j], j));
        }
        sort(arr.begin(), arr.end());
        rep(j,0,m) {
            p[i][arr[j].second] = j;
        }
    }
    rep(j,0,m) {
        vii arr;
        rep(i,0,n) {
            arr.push_back(ii(totalPlaytime[i][j], i));
        }
        sort(arr.begin(), arr.end());
        rep(i,0,n) {
            q[arr[i].second][j] = i;
        }
    }

    int **M = new int*[m];
    rep(i,0,m) M[i] = new int[m];

    rep(i,0,n) {
        vii arr;
        rep(j,0,m) {
            arr.push_back(ii(p[i][j],j));
        }
        sort(arr.begin(), arr.end());
        rep(j,0,m) {
            M[i][j] = arr[j].second;
        }
    }
    rep(i,n,m) {
        rep(j,0,m) {
            M[i][j] = j;
        }
    }

    int **W = new int*[m];
    rep(i,0,m) W[i] = new int[m];

    rep(j,0,m) {
        vii arr;
        rep(i,0,n) {
            arr.push_back(ii(q[i][j],i));
        }
        sort(arr.begin(), arr.end());
        rep(i,0,n) {
            W[j][i] = arr[i].second;
        }
        rep(i,n,m) {
            W[j][i] = i;
        }
    }

    vi res = stable_marriage(m, M, W);
    for (int i = 0; i < n; i++) {
        cout << res[i]+1 << endl;
    }

    return 0;
}
