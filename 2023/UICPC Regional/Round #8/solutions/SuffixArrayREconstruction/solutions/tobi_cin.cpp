// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <string>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

int main(int argc, char **argv) {
	int numCases;
	cin >> numCases;

	while (numCases --> 0) {
		int len, numSuff, pos;
		string buf, suff;

		cin >> len >> numSuff;
		buf = "";
		FOR(i, 0, len) buf += "*";

		bool possible = true;
		FOR(i, 0, numSuff) {
			cin >> pos >> suff;
			pos--;
			int suffLen = suff.size();
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
			cout << buf << endl;
		} else {
			cout << "IMPOSSIBLE" << endl;
		}
	}

	return 0;
}
