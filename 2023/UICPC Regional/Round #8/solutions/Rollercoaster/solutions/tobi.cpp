// @EXPECTED_RESULTS@: CORRECT

#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX_ITEMS 105
#define MAX_TIME 50005
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)

int table[MAX_TIME];
int fun[MAX_ITEMS][MAX_TIME];
int a[MAX_ITEMS], b[MAX_ITEMS], t[MAX_ITEMS];

int main(int argc, char **argv) {
	int numItems, maxTime;
	scanf("%d", &numItems);
	maxTime = MAX_TIME;
	FOR(i, 0, numItems) {
		scanf("%d%d%d", &a[i], &b[i], &t[i]);
		fun[i][0] = a[i];
		FOR(j, 1, maxTime+1) fun[i][j] = max(0, fun[i][j-1] - ((j*2)-1) * b[i]);
	}

	FOR(i, 0, numItems) {
		if (b[i] == 0) {
			FOR(j, t[i], maxTime+1) {
				int before = j - t[i];
				table[j] = max(table[j], table[before] + fun[i][0]);
			}
		} else {
			for (int j = 0; fun[i][j] > 0; j++) {
				FORD(k, t[i], maxTime+1) {
					table[k] = max(table[k], table[k - t[i]] + fun[i][j]);
				}
			}
		}
	}

	int numQ;
	scanf("%d", &numQ);
	FOR(i, 0, numQ) {
		int time;
		scanf("%d", &time);
		printf("%d\n", table[time]);
	}

	return 0;
}
