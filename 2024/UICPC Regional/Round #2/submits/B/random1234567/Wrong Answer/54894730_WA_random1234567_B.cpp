#include <iostream>
#include <math.h>
#define FOR(i,a,b) for(int i=1;i<=b;i++)
using namespace std;
int arr[110];

char s[300][300];
char ans[300];
int nist[300][5];

char solve(int w) {

	char ine='0';
	int na=0;
	FOR(i, 1, 4) {
		if (nist[w][i] == 0) {
			ine = i;
			na++;
		}
	}
	if (na > 1)return'?';
	if (ine == 1)return 'A';
	if (ine == 2)return 'B';
	if (ine == 3)return 'C';
	if (ine == 4)return 'D';

}
int main() {
	int t;
	cin >> t;
	int a, b;
	while (t--) {
		cin >> a >> b;
		FOR(i, 1, 250) {
			ans[i] = 0;
			FOR(j, 1, 4) {
				nist[i][j] = 0;
			}
		}
		FOR(i, 1, b) {
			FOR(j, 1, a * 2) {
				cin >> s[i][j];
				if (j % 2 == 0 && s[i][j] == 'T') {
					ans[j / 2] = s[i][j - 1];
				//	cout << "asd";
				}
				if (j % 2 == 0 && s[i][j] == 'F') {
					nist[j / 2][s[i][j - 1] - 'A' + 1] = -1;
				}
				//0 kardan
			}
		}
		FOR(i, 1, a) {
			if (ans[i] != 0) {
				cout << ans[i] << " ";
			}
			else {
				cout << solve(i) << " ";
			}
		}
		cout << endl;


	}
}
