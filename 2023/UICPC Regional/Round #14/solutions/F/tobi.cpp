// @EXPECTED_RESULTS@: CORRECT
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

string board[5];
int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, -1, +1};

bool valid(int x, int y, int X, int Y) {
	if (x + 2*X < 0 || x + 2*X >= 5 || y + 2*Y < 0 || y + 2*Y >= 9) return false;
	if (board[x + X][y + Y] == 'o' && board[x + 2*X][y + 2*Y] == '.') return true;
	return false;
}

int recur(int x, int y, int pegs) {
	if (pegs == 0) return 0;
	if (y >= 9) return pegs;
	if (x >= 5) return recur(0, y+1, pegs);

	int best = recur(x + 1, y, pegs);
	if (board[x][y] != 'o') return best;
	
	for (int i = 0; i < 4; i++) {
		if (!valid(x,y,dx[i],dy[i])) continue;
		board[x][y] = '.'; board[x + dx[i]][y + dy[i]] = '.'; board[x + 2*dx[i]][y + 2*dy[i]] = 'o';
		best = min(best, recur(0, 0, pegs - 1));
		board[x][y] = 'o'; board[x + dx[i]][y + dy[i]] = 'o'; board[x + 2*dx[i]][y + 2*dy[i]] = '.';
	}

	return best;
}

int main() {
	int numCases;
	cin >> numCases;

	while (numCases --> 0) {
		int pegs = 0;
		for (int i = 0; i < 5; i++) {
			cin >> board[i];
			for (unsigned int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == 'o') pegs++;
			}
		}
		assert(pegs <= 8);
		int mini = recur(0,0,pegs);
		cout << mini << " " << (pegs - mini) << endl;
	}

	return 0;
}
