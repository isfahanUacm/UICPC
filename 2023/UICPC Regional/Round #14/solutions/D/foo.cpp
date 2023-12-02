// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <list>
#include <cmath>
#include <cstring>
using namespace std;

bool mark[1000];
int c[1000][2];
list<int> q;

bool graph[1000][1000];

int main() {
	int ntc;
	cin >> ntc;
	while (ntc--) {
		int tclen;
		cin >> tclen;
		tclen += 2;
		for(int i = 0; i < tclen; i++) {
			cin >> c[i][0];
			cin >> c[i][1];
			mark[i] = false;
		}
		// memset(graph, 0, sizeof graph);
		// for(int i = 0; i < tclen; i++) {
		// 	for(int j = 0; j < tclen; j++) {
		// 		if(i != j && abs(c[i][0] - c[j][0]) 
		// 		   + abs(c[i][1] - c[j][1]) <= 1000) {
		// 			cerr << "1";
		// 		} else {
		// 			cerr << "0";
		// 		}
		// 	}
		// 	cerr << endl;
		// }
		// cerr << endl;
		q.clear();
		q.push_back(0);
		while(!q.empty()) {
			int i = q.front();
			q.pop_front();
			if(mark[i]) continue;
			mark[i] = true;
			//cout << "Visiting " << c[i][0] << ", " << c[i][1] << endl;
			for(int j = 0; j < tclen; j++) {
				if(i == j) continue;
				if(    abs(c[i][0] - c[j][0]) 
				     + abs(c[i][1] - c[j][1]) <= 1000) {
					q.push_back(j);
				}
			}
		}
		cout << (mark[tclen-1] ? "happy" : "sad") << endl;
	}
	
	return 0;
}
