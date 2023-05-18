#include <iostream>
#include <vector>

using namespace std;

int main() {
	int R, C;
	cin >> R >> C;

	vector<int> eastProposal(R);
	for (int i=0; i<R; i++) cin >> eastProposal[i];
	vector<int> northProposal(C);
	for (int i=0; i<C; i++) cin >> northProposal[i];

	vector<vector<int>> cityGrid(R,vector<int>(C));
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			cityGrid[i][j] = min(eastProposal[i], northProposal[j]);
		}
	}

	bool ok = true;
	for (int i=0; i<R; i++) {
		int cur=0;
		for (int j=0; j<C; j++) {
			cur = max(cur, cityGrid[i][j]);
		}
		if (cur != eastProposal[i]) ok = false;
	}
	for (int j=0; j<C; j++) {
		int cur=0;
		for (int i=0; i<R; i++) {
			cur = max(cur, cityGrid[i][j]);
		}
		if (cur != northProposal[j]) ok = false;
	}

	if (ok)
		cout << "possible" << endl;
	else
		cout << "impossible" << endl;

	return 0;
}
