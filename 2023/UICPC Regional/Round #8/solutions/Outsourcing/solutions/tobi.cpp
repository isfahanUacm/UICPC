// @EXPECTED_RESULTS@: CORRECT

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 250
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define sz(c) int((c).size())
typedef pair<int, int> pii;

int numAS[2], numTS[2], numOp[2];
vector<pii> adjList[2][MAX];
vector<int> revList[2][MAX];
bool productive[2][MAX], traversed[MAX][MAX];

void prod(int factory, int node) {
	if (productive[factory][node]) return;
	productive[factory][node] = true;
	FOR(i, 0, sz(revList[factory][node])) prod(factory, revList[factory][node][i]);
}

bool same(int left, int right) {
	if (left == numTS[0] - 1 && right != numTS[1] - 1) return false;
	if (left != numTS[0] - 1 && right == numTS[1] - 1) return false;
	if (traversed[left][right]) return true;
	traversed[left][right] = true;

	int leftP = 0; int rightP = 0;
	while (true) {
		while (leftP < sz(adjList[0][left]) && !productive[0][adjList[0][left][leftP].second]) leftP++;
		while (rightP < sz(adjList[1][right]) && !productive[1][adjList[1][right][rightP].second]) rightP++;
		if (leftP >= sz(adjList[0][left]) && rightP < sz(adjList[1][right])) return false;
		if (leftP < sz(adjList[0][left]) && rightP >= sz(adjList[1][right])) return false;
		if (leftP >= sz(adjList[0][left]) && rightP >= sz(adjList[1][right])) return true;
		if (adjList[0][left][leftP].first != adjList[1][right][rightP].first) return false;
		if (!same(adjList[0][left][leftP].second, adjList[1][right][rightP].second)) return false;
		leftP++; rightP++;
	}
}

int main(int argc, char **argv) {
	int numCases, from, to, label;
	scanf("%d", &numCases);

	while (numCases --> 0) {
		FOR(i, 0, 2) {
			scanf("%d%d%d", numAS+i, numTS+i, numOp+i);
			FOR(j, 0, numTS[i]) {
				adjList[i][j].clear();
				revList[i][j].clear();
				productive[i][j] = false;
			}
		}
		FOR(i, 0, numTS[0]) FOR(j, 0, numTS[1]) traversed[i][j] = false;
		FOR(i, 0, 2) {
			FOR(j, 0, numAS[i]) {
				scanf("%d%d%d", &from, &to, &label);
				pii next = pii(label,to);
				adjList[i][from].push_back(next);
				revList[i][to].push_back(from);
			}
			FOR(j, 0, numTS[i]) sort(adjList[i][j].begin(), adjList[i][j].end());
			prod(i, numTS[i] - 1);
		}
		printf("%s\n", same(0,0) ? "eligible" : "not eligible");
	}

	return 0;
}
