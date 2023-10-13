// @EXPECTED_RESULTS@: CORRECT

#include <stdio.h>
#include <string.h>

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

int main(int argc, char **argv) {
	int numCases;
	scanf("%d", &numCases);

	while (numCases --> 0) {
		int len, numSuff, pos;
		char buf[10005], suff[10005];

		scanf("%d%d", &len, &numSuff);
		FOR(i, 0, len) buf[i] = '*';
		buf[len] = '\0';

		bool possible = true;
		FOR(i, 0, numSuff) {
			scanf("%d%s", &pos, suff);
			pos--;
			int suffLen = strlen(suff);
			FOR(j, 0, suffLen) {
				if (suff[j] == '*') {
					break;
				} else if (buf[j + pos] == '*' || buf[j + pos] == suff[j]) {
					buf[j + pos] = suff[j];
				} else {
					possible = false;
					break;
				}
			}
			FOR(j, 0, suffLen) {
				if (suff[suffLen - j - 1] == '*') {
					break;
				} else if (buf[len - j - 1] == '*' || buf[len - j - 1] == suff[suffLen - j - 1]) {
					buf[len - j - 1] = suff[suffLen - j - 1];
				} else {
					possible = false;
					break;
				}
			}
		}
		FOR(i, 0, len) {
			if (buf[i] == '*') {
				possible = false;
			}
		}
		if (possible) {
			printf("%s\n", buf);
		} else {
			puts("IMPOSSIBLE");
		}
	}

	return 0;
}
