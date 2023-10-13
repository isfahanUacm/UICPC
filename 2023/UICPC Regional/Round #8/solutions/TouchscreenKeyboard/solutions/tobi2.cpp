// @EXPECTED_RESULTS@: CORRECT

#include <stdio.h>
#include <algorithm>
#include <set>
#include <string>
#include <string.h>

using namespace std;

char keyboard[3][11] = {
"qwertyuiop",
"asdfghjkl#",
"zxcvbnm###"
};

int main(int argc, char **argv) {
	int mapping[256][2];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			mapping[(int) keyboard[i][j]][0] = i;
			mapping[(int) keyboard[i][j]][1] = j;
		}
	}
	int numCases;
	scanf("%d", &numCases);

	while (numCases --> 0) {
		int numStrings;
		multiset<pair<int,string> > result;
		char buf[10005], orig[10005];
		scanf("%s%d", orig, &numStrings);

		for (int i = 0; i < numStrings; i++) {
			int cur = 0;
			scanf("%s", buf);
			for (int i = 0; i < (signed) strlen(buf); i++) {
				cur += abs(mapping[(int)buf[i]][0] - mapping[(int)orig[i]][0]) +
					abs(mapping[(int)buf[i]][1] - mapping[(int)orig[i]][1]);
			}

			result.insert(make_pair(cur,string(buf)));
		}

		for (multiset<pair<int,string> >::iterator it = result.begin(); it != result.end(); it++) {
			printf("%s %d\n", it->second.c_str(), it->first);
		}
	}

	return 0;
}
