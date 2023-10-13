// @EXPECTED_RESULTS@: CORRECT

#include <stdio.h>
#include <algorithm>
#include <set>
#include <string>
#include <string.h>
#include <assert.h>

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
	int distMatrix[256][256];
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < 256; j++) {
			distMatrix[i][j] = abs(mapping[i][0] - mapping[j][0]) +
				abs(mapping[i][1] - mapping[j][1]);
		}
	}
	int numCases;
	scanf("%d", &numCases);

	while (numCases --> 0) {
		int numStrings;
		multiset<pair<int,string> > result;
		char buf[10005], orig[10005];
		scanf("%s%d", orig, &numStrings);

		set<string> s;
		for (int i = 0; i < numStrings; i++) {
			int cur = 0;
			scanf("%s", buf);
			assert(strlen(buf) == strlen(orig));
			assert(s.find(string(buf)) == s.end());
			s.insert(string(buf));
			for (int i = 0; i < (signed) strlen(buf); i++) {
				cur += distMatrix[(int)buf[i]][(int)orig[i]];
			}

			result.insert(make_pair(cur,string(buf)));
		}

		for (multiset<pair<int,string> >::iterator it = result.begin(); it != result.end(); it++) {
			printf("%s %d\n", it->second.c_str(), it->first);
		}
	}

	return 0;
}
