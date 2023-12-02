// @EXPECTED_RESULTS@: CORRECT
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <limits.h>

using namespace std;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define add_edge(a,b,c)  adj[(a)].push_back((b)); adj[(b)].push_back((a)); residual[(a)][(b)] += (c);

int grid[305][305];
int dx[] = {-1, 0, 0, +1};
int dy[] = {0, +1, -1, 0};
const int MAXN = 2*(305 * 305) + 50;
int N, S, T, r, c, castleR, castleC, flow;
int previous[MAXN];
vector<int>  adj[MAXN];
map<int,int> residual[MAXN];
const int oo = INT_MAX / 3;
 
bool find_path() {
	memset(previous, -1, sizeof(previous));
	previous[S] = S;
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		FOR(i, 0, (signed) adj[n].size()) {
			int m = adj[n][i];
			if (previous[m] == -1 && residual[n][m]) {
				previous[m] = n;
				q.push(m);
				if (m == T) return true;
			}
		}
	}
	return false;
}

int augment(int n, int cap) {
	if (previous[n] == n) return cap;
	cap = augment(previous[n], min(cap, residual[previous[n]][n]));
	residual[previous[n]][n] -= cap;
	residual[n][previous[n]] += cap;
	return cap;
}

int main() {
	cin >> r >> c;
	FOR(i, 0, r) FOR(j, 0, c) cin >> grid[i][j];
	cin >> castleR >> castleC;
	S = 2*r*c; T = S + 1; N = T + 1;
	FOR(i, 0, r) FOR(j, 0, c) {
		FOR(k, 0, 4) {
			if (i+dy[k] < 0 || j+dx[k] < 0 || i+dy[k] >= r || j+dx[k] >= c) continue;
			add_edge(r*c+i*c + j, (i+dy[k])*c + j+dx[k], oo);
		}
		add_edge(i*c + j, r*c + i*c + j, grid[i][j]);
	}
	add_edge(S, castleR*c + castleC, oo);
	FOR(i, 0, r) {
		add_edge(r*c+i*c + 0, T, oo);
		add_edge(r*c+i*c + c-1, T, oo);
	}
	FOR(i, 0, c) {
		add_edge(r*c+0*c + i, T, oo);
		add_edge(r*c+(r-1)*c + i, T, oo);
	}
	while (find_path()) flow += augment(T, oo);
	cout << flow << endl;

	return 0;
}
