// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

bool table[8][8][8][8];

int dx[] = {1, 1, -1, -1};
int dy[] = {-1, 1, -1, 1};

void inline move(int i, int j, int k, int l) {
	if (k < 0 || k > 7 || l < 0 || l > 7) return;
	table[i][j][k][l] = true;
}

void inline pos(int i, int j) {
	cout << " " << (char) ('A' + i) << " " << j + 1;
}

int main() {
	FOR(i, 0, 8) FOR(j, 0, 8) FOR (k, 1, 8) FOR(l, 0, 4) move(i,j, i + k*dx[l], j + k*dy[l]);

	int nC;
	cin >> nC;

	while (nC --> 0) {
		string fromS, toS;
		int fromI, toI;
		int fromC, toC;
		cin >> fromS >> fromI >> toS >> toI;
		fromC = fromS[0] - 'A';
		toC = toS[0] - 'A';
		fromI--; toI--;
		if (((fromC + toC) % 2) != ((fromI + toI) % 2)) {
			cout << "Impossible" << endl;
		} else if (fromC == toC && fromI == toI) {
			cout << "0"; pos(fromC, fromI); cout << endl;
		} else if (table[fromC][fromI][toC][toI]) {
			cout << "1"; pos(fromC, fromI); pos(toC, toI); cout << endl;
		} else {
			FOR(i, 0, 8) FOR (j, 0, 8) if (table[fromC][fromI][i][j] && table[i][j][toC][toI]) {
				cout << "2"; pos(fromC, fromI); pos(i,j); pos(toC, toI); cout << endl;
				goto found;
			}
found:;
		}
	}

	return 0;
}
