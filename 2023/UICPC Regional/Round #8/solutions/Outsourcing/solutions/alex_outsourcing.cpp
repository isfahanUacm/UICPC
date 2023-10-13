// @EXPECTED_RESULTS@: CORRECT
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

const int MAXM = 50111, MAXN = 1111;
int ed_from[2][MAXM], ed_to[2][MAXM], ed_col[2][MAXM], N[2], M[2], S[2];
pair<int,pii > ed_tmp[MAXM];
vector<int> adj[2][MAXN];
bool vis[MAXN], same[MAXN][MAXN];

bool check(){
	FOR(id,0,2){
		FOR(j,0,N[id])adj[id][j].clear();
		FOR(j,0,M[id])adj[id][ed_from[id][j]].push_back(j);
	}
	FOR(i,0,N[0])FOR(j,0,N[1])same[i][j] = 0;
	same[0][0] = 1;
	queue<pii > q = queue<pii >();
	q.push(pii(0,0));
	while(!q.empty()){
		pii nn = q.front();
		q.pop();
		int n1 = nn.first, n2 = nn.second;
		if(sz(adj[0][n1])!=sz(adj[1][n2]))return false;
		FOR(i,0,sz(adj[0][n1])){
			int m1 = adj[0][n1][i], m2 = adj[1][n2][i];
			if(ed_col[0][m1] != ed_col[1][m2])return false;
			int t1 = ed_to[0][m1], t2 = ed_to[1][m2];
			if((t1 == N[0] - 1) != (t2 == N[1] - 1))return false;
			if(!same[t1][t2]){
				same[t1][t2] = 1;
				q.push(pii(t1,t2));
			}
		}
	}
	return true;
}
// shrink removes all nodes, which can't be reached from node 0 or which can't reach node N-1
void shrink(int id){
	FOR(k,0,2){
		FOR(i,0,N[id])adj[id][i].clear();
		if(k)FOR(i,0,M[id])adj[id][ed_from[id][i]].push_back(ed_to[id][i]);
		else FOR(i,0,M[id])adj[id][ed_to[id][i]].push_back(ed_from[id][i]);
		FOR(i,0,N[id])vis[i] = 0;
		int start = (1-k) * (N[id] - 1);
		vis[start] = 1;
		queue<int> q = queue<int>();
		q.push(start);
		while(!q.empty()){
			int n = q.front();
			q.pop();
			FOR(i,0,sz(adj[id][n])){
				if(!vis[adj[id][n][i]]){
					q.push(adj[id][n][i]);
					vis[adj[id][n][i]] = 1;
				}
			}
		}
		FOR(i,0,M[id])if(!vis[ed_from[id][i]]||!vis[ed_to[id][i]]){
			--M[id];
			swap(ed_from[id][i],ed_from[id][M[id]]);
			swap(ed_to[id][i],ed_to[id][M[id]]);
			swap(ed_col[id][i--],ed_col[id][M[id]]);
		}
	}
}
int main() {
	int tc;
	cin >> tc;
	while(tc--){
		FOR(i,0,2)cin >> M[i] >> N[i] >> S[i];
		FOR(i,0,2){
			FOR(j,0,M[i])cin >> ed_from[i][j] >> ed_to[i][j] >> ed_col[i][j];
			shrink(i);
			FOR(j,0,M[i])ed_tmp[j] = make_pair(ed_col[i][j],pii(ed_from[i][j], ed_to[i][j]));
			sort(ed_tmp,ed_tmp+M[i]);
			FOR(j,0,M[i]){
				ed_col[i][j] = ed_tmp[j].first;
				ed_from[i][j] = ed_tmp[j].second.first;
				ed_to[i][j] = ed_tmp[j].second.second;
			}
		}
		if(!check())cout << "not ";
		cout << "eligible\n";
	}
	return 0;
}
