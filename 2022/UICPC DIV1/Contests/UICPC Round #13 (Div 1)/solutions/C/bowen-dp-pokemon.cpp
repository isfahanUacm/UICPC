/*
  Dynamic programming with bitmask keeping track of
  - The current location.
  - Which pokemons have been caught.
  This has running time of O(L^2 * 2^M), where L is the number of locations,
  and M is the number of distinct pokemons.
*/
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
#define MAXN 100005

map<string, int> pid;
map<PII, int> lid, pokemon;
map<int, int> pokemask;
PII loc[21];
int N, M, L, S, dp[21][1<<15];
int dist(int i, int j) {
  return abs(loc[i].first - loc[j].first) + abs(loc[i].second - loc[j].second);
}
int solve(int x, int m) {
  if (m == (1<<M)-1) return dist(x, S);
  if (dp[x][m] != -1) return dp[x][m];
  int ans = INF;
  REP(y,0,L) {
    int nm = m | pokemask[y];
    if (nm == m) continue;
    ans = min(ans, solve(y, nm) + dist(x, y));
  }
  return dp[x][m] = ans;
}

int main() {
  cin >> N;
  REP(i,0,N) {
    int x, y;
    string s;
    cin >> x >> y >> s;
    if (pid.find(s) == pid.end()) pid[s] = M++;
    pokemon[PII(x,y)] |= 1 << pid[s];
  }
  pokemon[PII(0,0)]; // touch initial point
  for (auto it = pokemon.begin(); it != pokemon.end(); it++) {
    lid[it->first] = L;
    loc[L] = it->first;
    pokemask[L] = it->second;
    L++;
  }
  FILL(dp, -1);
  S = lid[PII(0, 0)];
  cout << solve(S, pokemask[S]) << endl;
  return 0;
}
