#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long ll;

void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack, vector<vector<ll>>& adj ) {
	visited[v] = true;
	for (auto i = 0; i < adj.size(); ++i)
		if (adj[v][i] >= 0 and !visited[i])
			topologicalSortUtil(i, visited, Stack, adj );
	Stack.push(v);
}
 
vector<int> topologicalSort( vector<vector<ll>> & adj ) {
	stack<int> Stack;
	int V = adj.size();
	vector<bool> visited( V, false );
	for( int i = 0; i < V; i++ )
		if( not visited[i] )
			topologicalSortUtil( i, visited, Stack, adj );
	vector<int> topOrder(V);
 	for( int i = 0; i < V; i++) {
		topOrder[i] = Stack.top();
		Stack.pop();
	}
	return topOrder;
}


int main() {
	int V;
	cin >> V;

	vector<vector<ll>> Avg(V, vector<ll>(V));
	for( int i = 0; i < V; i++ ) {
		for( int j = 0; j < V; j++ ) 
			cin >> Avg[i][j];
	}


	auto topOrder = topologicalSort( Avg );

	// reverse topOrder
	reverse( topOrder.begin(), topOrder.end());	

	// edges
	vector<vector<ll>> E(V, vector<ll>(V,-1));

	// number of paths i -> j
	vector<vector<ll>> M(V, vector<ll>(V,0));

	for( int k = 0; k < V; k++ ) {
		int i = topOrder[k];
		for( int l = k-1; l >= 0; --l ) {
			int j = topOrder[l];
			if( Avg[i][j] < 0 )
				continue;

			//cout << "Path from " << i << " to " << j << ": " << Avg[i][j] << endl;

			// compute number and length of all paths from i to j
			ll number = 0;
			ll sm = 0; 
			for( int m = l+1; m < k; m++ ) {
				int p = topOrder[m];
				if( E[i][p] < 0 )
					continue;
				number += M[p][j];
				sm += M[p][j] * (E[i][p] + Avg[p][j]);
			}
			M[i][j] = number;

			//cout << "#existing paths: " << number << " of total length " << sm << endl;

			ll scaled_avg = number * Avg[i][j];
			if( scaled_avg != sm or number == 0 ) {
				E[i][j] = (scaled_avg + Avg[i][j]) - sm;
				M[i][j]++;
			}

		}
	}

	for( int i = 0; i < V; i++ ) {
		for( int j = 0; j < V; j++ ) 
			cout << E[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	return 0;
}
