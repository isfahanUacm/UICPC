// @EXPECTED_RESULTS@: CORRECT

#include <stdio.h>

#define MAX 35
#define MAX_S 2005

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

bool grid[MAX][MAX][2];
int shots[MAX_S][2];
int numShips[2];
char buf[MAX * 2];

int main(int argc, char **argv) {
	int numCases, width, height, numShots;
	scanf("%d", &numCases);

	while (numCases --> 0) {
		scanf("%d%d%d", &width, &height, &numShots);

		FOR(i, 0, 2) {
			numShips[i] = 0;
			FOR(j, 0, height) {
				scanf("%s", buf);
				FOR(k, 0, width) {
					grid[j][k][i] = (buf[k] == '#');
					numShips[i] += (buf[k] == '#');
				}
			}
		}

		FOR(i, 0, numShots) {
			scanf("%d%d", &shots[i][0], &shots[i][1]);
			shots[i][1] = height - 1 - shots[i][1];
		}

		int curP = 0; int othP = 1;
		FOR(curS, 0, numShots) {
			if (grid[shots[curS][1]][shots[curS][0]][othP]) {
				grid[shots[curS][1]][shots[curS][0]][othP] = false; 
				numShips[othP]--;
				if (numShips[othP] == 0) {
					if(othP == 0) {
						break;
					} else {
						curP = 1 - curP;
						othP = 1 - othP;
					}
				}
			} else {
				if (numShips[curP] == 0 && curP == 1) {
					break;
				}
				curP = 1 - curP;
				othP = 1 - othP;
			}
		}

		if (numShips[0] == 0 && numShips[1] == 0) {
			puts("draw");
		} else if (numShips[0] == 0) {
			puts("player two wins");
		} else if (numShips[1] == 0) {
			puts("player one wins");
		} else {
			puts("draw");
		}
	}

	return 0;
}
