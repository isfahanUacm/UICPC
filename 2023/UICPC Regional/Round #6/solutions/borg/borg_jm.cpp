#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int N, L, totalEdges = 0;
	cin >> N >> L;
	vector<vector<int> > adj(N);
	vector<int> walk(L);
	for(int i=0;i<L;i++) cin >> walk[i];
	for(int i=0;i<N;i++) {		
		int k,x;
		cin >> k;
		while (k--) {
			cin >> x;
			adj[i].push_back(x);
		}
		totalEdges += adj[i].size();
	}
	vector<double> borgProb(N);
	for (int i = 0; i < N; i++)
		borgProb[i] = (double) adj[i].size() / totalEdges;
	double risk = 1.0 - borgProb[walk[0]];
	for (int i = 1; i < L; i++) {			
		int current = walk[i-1], next = walk[i];
		borgProb[current] = 0.0;
		vector<double> newBorgProb(N, 0);
		for (int j = 0; j < N; j++)
			for(int k = 0; k < adj[j].size(); k++)
				newBorgProb[adj[j][k]] += borgProb[j] / adj[j].size();
		risk -= borgProb[next] / adj[next].size();
		risk -= newBorgProb[next];
		newBorgProb[current] -= borgProb[next] / adj[next].size();
		borgProb = newBorgProb;		
	}
	
	cout << risk << endl;
	
	return 0;
}
