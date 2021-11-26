#include <bits/stdc++.h> 
using namespace std; 
#define MAX_N 200003
long long int level[MAX_N]; 
int anc[20][MAX_N];
vector<int> g[MAX_N];
int n, uu, vv;
void dfs(int node, int parent) 
{ 
	if (parent == -1) { 
		level[node] = 0; 
	} 
	else { 
		level[node] = level[parent] + 1; 
        anc[0][node] = parent;
	} 
	for (auto i : g[node]) { 
		if (i != parent) {
			dfs(i, node);
		} 
	} 
} 

int findLCA(int a, int b) 
{ 
    if (level[a] < level[b]) {
          a ^= b;
          b ^= a;
          a ^= b;
    }
    int diff = level[a] - level[b];
    for (int i = 0; 1 << i <= diff; i++)
      if ((diff & (1 << i)) != 0) {
        a = anc[i][a];
      }
    
    if (a == b)
      return a;

    int log = 0;
    while (1 << (log + 1) <= level[a])
        log++;

    for (int i = log; i >= 0; i--)
        if (anc[i][a] != anc[i][b]) {
            a = anc[i][a];
            b = anc[i][b];
        }
    return anc[0][a];
} 

int main() 
{   
    cin>>n;
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < n+1; ++j)
            anc[i][j]=-1;
    for (int i = 0; i < n-1; ++i) {
        cin>>uu>>vv;
        g[uu].push_back(vv);
        g[vv].push_back(uu);
    }
    dfs(1, -1);
    for (int k = 1; 1 << k < n; k++)
          for (int i = 1; i <= n; i++)
            anc[k][i] = anc[k - 1][i] == -1 ? -1 : anc[k - 1][anc[k - 1][i]];
    long long int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 2*i; j <= n; j+=i) {
            res += level[i] + level[j] - 2 * level[findLCA(i, j)] + 1;
        }
    }
    cout<<res<<endl;
} 
