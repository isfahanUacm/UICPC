#include<bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

vector<int> removed;
bool inpath[100000];


void DFSUtil(int u, vector<pi> adj[], vector<bool>&visited){
    visited[u] = true;
    inpath[u] = true;
    //cerr << "visiting" << u << endl;
    for (int i=0; i < adj[u].size(); i++){
        if (inpath[adj[u][i].second] == true){
            //cerr << "found to remove " << u << " " << adj[u][i].second << endl;
            removed.push_back(adj[u][i].first);
        }
        if (visited[adj[u][i].second] == false){


            DFSUtil(adj[u][i].second, adj, visited);
        }
    }
    //cerr << "exit " << u << endl;
    inpath[u] = false;
}

void DFS(vector<pi> adj[], int V){
    vector<bool> visited(V, false);
	vector<int> u(V);
	iota(begin(u), end(u), 0);
	random_shuffle(begin(u), end(u));
    for (auto x : u){
        if (visited[x] == false){
            DFSUtil(x, adj, visited);
        }
    }
}

int main(){
    int N, M;
    int u, v;



    cin >> N >> M;
    vector<pi> adj[N];

    for (int i=0; i < M; i++){
        cin >> u >> v;
        adj[u-1].push_back(make_pair(i, v-1));
    }
	do {
		removed.clear();
		for (int i=0; i < 100000; i++)
			inpath[i] = false;
		DFS(adj, N);
	} while(removed.size()*2 > M);
    cout << removed.size() << endl;
    for (int i=0; i < removed.size(); i++)
        cout << removed[i]+1 << endl;
    return 0;
}
