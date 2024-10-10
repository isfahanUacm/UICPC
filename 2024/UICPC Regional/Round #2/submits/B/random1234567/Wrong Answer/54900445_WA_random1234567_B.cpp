#include <iostream>
#include <math.h>
#define FOR(i,a,b) for(int i=1;i<=b;i++)
using namespace std;
const int MAX = 300;
int arr[MAX][4];


int t;

void reload() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = 0;
		}
	}
}
void solve2() {
	reload();
	int num, c;
	cin >> num >> c;

	while (c--) {
		for (int q = 0; q < num; q++) {
			string answer, T_F;
			cin >> answer >> T_F;
			arr[q][answer[0] - 'A'] = ((T_F[0] == 'T') ? 1 : -1);
		}
	}

	for (int q = 0; q < num; q++) {
		bool found = false;
		int falses = 0;
		for (int i = 0; i < 4; i++) {
			if (arr[q][i] == 1) {
				cout << char('A' + i) << ' ';
				found = true;
				break;
			}
			else if (arr[q][i] == -1) {
				falses++;
			}
		}

		if (!found) {
			if (falses == 3) {
				for (int i = 0; i < 4; i++) {
					if (!arr[q][i]) {
						cout << char('A' + i) << ' ';
					}
				}
			}
			else {
				cout << '?' << ' ';
			}
		}

	}
	if(t!=0)
		cout << endl;





}
int main() {
	cin >> t;
	while (t--) {
		solve2();
	}
	return 0;

}
