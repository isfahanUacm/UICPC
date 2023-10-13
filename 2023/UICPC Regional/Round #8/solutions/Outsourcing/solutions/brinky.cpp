// @EXPECTED_RESULTS@: CORRECT
#include <cstdio>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

list<pair<int, int> > G[2][2][250];

int r[250];

int ok[250][250];

void reach(int g, int d, int n){
	if(r[n] == d+1 || r[n] < d)
		return;
	r[n] = d+1;
	for(list<pair<int, int> >::iterator iter = G[d][g][n].begin(); iter != G[d][g][n].end(); ++iter){
		reach(g, d, iter->second);
	}
}

int main(){
	int tcn, M[2], N[2], K[2];
	scanf("%d", &tcn);
	while(tcn--){
		for(int i=2; i--;){
			for(int j=250; j--;){
				for(int k=2; k--;){
					G[k][i][j].clear();
				}
			}
		}
		for(int i=2; i--;){
			scanf("%d %d %d", &M[i], &N[i], &K[i]);
		}
		for(int i=2; i--;){
			for(int j=0; j<M[i]; ++j){
				int a, o, l;
				scanf("%d %d %d", &a, &o, &l);
				G[0][i][a].push_back(make_pair(l, o));
				G[1][i][o].push_back(make_pair(l, a));
			}
		}
		for(int i=2; i--;){
			memset(r, 0, sizeof(r));
			for(int j=0; j<2; ++j){
				reach(i, j, !j ? 0 : N[i] - 1);
			}
			for(int j=0; j<N[i]; ++j){
				if(r[j] != 2){
					G[0][i][j].clear();
				}
				for(list<pair<int, int> >::iterator iter = G[0][i][j].begin(); iter != G[0][i][j].end();){
					if(r[iter->second] != 2){
						iter = G[0][i][j].erase(iter);
					}else{
						++iter;
					}
				}
				G[0][i][j].sort();
			}
		}
		queue<pair<int, int> > q;
		q.push(make_pair(0, 0));
		bool works = true;
		while(!q.empty() && works){
			int a = q.front().first;
			int b = q.front().second;
			q.pop();
			ok[a][b] = tcn+1;
			if(		  (a == N[0]-1 && b != N[1]-1)
					||(a != N[0]-1 && b == N[1]-1)
					||(G[0][0][a].size() != G[0][1][b].size())){
				works = false;
				break;
			}
			list<pair<int, int> >::iterator iter0;
			list<pair<int, int> >::iterator iter1;
			for(iter0 = G[0][0][a].begin(), iter1 = G[0][1][b].begin(); iter0 != G[0][0][a].end(); ++iter0, ++iter1){
				if(iter0->first != iter1->first){
					works = false;
					break;
				}
				if(ok[iter0->second][iter1->second] != tcn+1){
					q.push(make_pair(iter0->second, iter1->second));
				}
			}
		}
		if(works){
			puts("eligible");
		}else{
			puts("not eligible");
		}
	}
}
