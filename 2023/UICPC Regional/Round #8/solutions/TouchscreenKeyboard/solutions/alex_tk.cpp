// @EXPECTED_RESULTS@: CORRECT

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

string keyboard[3] = {"qwertyuiop","asdfghjkl","zxcvbnm"}, res, cur;
int x[256],y[256], tc, N;
int main() {
	FOR(i,0,3)FOR(j,0,keyboard[i].size()){
		x[keyboard[i][j]] = i;
		y[keyboard[i][j]] = j;
	}
	cin >> tc;
	while(tc--){
		cin >> res >> N;
		vector<pair<int,string> > liste = vector<pair<int,string> >(N);
		while(N--){
			cin >> cur;
			int dif = 0;
			FOR(i,0,res.size())dif += abs(x[res[i]]-x[cur[i]]) + abs(y[res[i]]-y[cur[i]]);
			liste[N] = make_pair(dif,cur);
		}
		sort(all(liste));
		FOR(i,0,liste.size())cout << liste[i].second << " " << liste[i].first << endl;
	}
	return 0;
}
