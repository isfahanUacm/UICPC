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
			FOR(j, 0, (signed) suff.size()) {
				if (suff[j] == '*') {
					break;
				} else if (buf[j + pos] == '*' || buf[j + pos] == suff[j]) {
					buf[j + pos] = suff[j];
				} else {
					possible = false;
					break;
				}
			}
			FOR(j, 0, (signed) suff.size()) {
				if (suff[(signed) suff.size() - j - 1] == '*') {
					break;
				} else if (buf[len - j - 1] == '*' || buf[len - j - 1] == suff[(signed) suff.size() - j - 1]) {
					buf[len - j - 1] = suff[(signed) suff.size() - j - 1];
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
