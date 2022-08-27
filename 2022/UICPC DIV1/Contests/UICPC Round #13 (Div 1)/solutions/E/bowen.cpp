#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 5005

int N, K, S, a[MAXN];
int cnt[MAXN][MAXN], dp[MAXN][MAXN][2];
VI choices[MAXN];
int main() {
  cin >> N >> K >> S;
  REP(i,0,N) scanf("%d", a+i);
  REP(k,0,K) {
    for (int i = k; i < N; i += K) {
      cnt[k][a[i]]++;
      choices[k].push_back(a[i]);
    }
    // Choices[k] stores the distinct values in group(k).
    sort(choices[k].begin(), choices[k].end());
    choices[k].erase(unique(choices[k].begin(), choices[k].end()), choices[k].end());
  }
  REP(i,0,K) REP(s,0,S+1) REP(t,0,2) dp[i][s][t] = INF;
  int tot = N / K + (N % K > 0);
  // Initializes the choice costs for group(0).
  REP(i,0,(int)choices[0].size()) {
    // Change all elements in group(0) to v.
    int v = choices[0][i];
    dp[0][v][0] = tot - cnt[0][v];
  }
  // Change all elements in group(0), but postpone the decision on their values.
  dp[0][0][1] = tot;
  REP(k,1,K) {
    tot = N / K + (k < N % K);
    REP(s,0,S+1) {
      REP(t,0,2) {
        int pre = dp[k-1][s][t];
        if (pre == INF) continue;
        REP(i,0,(int)choices[k].size()) {
          int v = choices[k][i];
          if (s + v > S) break;
          // Change all elements in group(k) to v.
          dp[k][s + v][t] = min(dp[k][s + v][t], pre + tot - cnt[k][v]);
        }
        // Change all elements in group(k), but postpone the decision on their values.
        dp[k][s][1] = min(dp[k][s][1], pre + tot);
      }
    }
  }
  // If we didn't postpone any decisions, then we must obtain an exact sum of S.
  int ans = dp[K-1][S][0];
  // If we postponed some decision, then we must be able to modify them so that the sum is S.
  REP(s,0,S+1) ans = min(ans, dp[K-1][s][1]);
  cout << ans << endl;
  return 0;
}
