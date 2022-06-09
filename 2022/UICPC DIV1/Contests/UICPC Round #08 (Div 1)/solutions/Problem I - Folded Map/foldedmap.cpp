#include <bits/stdc++.h>
using namespace std;

const int maxn = 2003;
char matrix[maxn][maxn];
int cnt[maxn][maxn];
int R, C;

int calc(int a, int b, int c, int d) { 
	int res = cnt[c][d];
	if (b)
		res -= cnt[c][b - 1];
	if (a)
		res -= cnt[a - 1][d];
	if (a && b)
		res += cnt[a - 1][b - 1];
	return res; 
}

int main() {
	int ar, ac, tr, tc;
	while (cin >> ar >> ac >> tr >> tc) {
		for (int i = 0; i < ar; ++i) {
			for (int j = 0; j < ac; ++j) {
				cin >> matrix[i][j];
			}
		}
		for (int i = 0; i < 2003; ++i) {
			for (int j = 0; j < 2003; ++j) {
				cnt[i][j] = 0;
			}
		}

		for (int i = 0; i < ar; ++i) {
			for (int j = 0; j < ac; ++j) {
				cnt[i + tr + 1][j + tc + 1] = ((matrix[i][j] == 'X') ? 1 : 0);
			}
		}
		R = ar + tr + 1;
		C = ac + tc + 1;
		int answer = INT_MAX;
		for (int i = 0; i <= R + tr; ++i) {
			for (int j = 1; j <= C + tc; ++j) {
				cnt[i][j] += cnt[i][j - 1];
			}
			if (i == 0) 
				continue;
			for (int j = 0; j <= C + tc; ++j) {
				cnt[i][j] += cnt[i - 1][j];
			}
		}
		for (int i = 0; i < tr; ++i) {
			for (int j = 0; j < tc; ++j) {
				int c = 0;
				for (int a = i; a < R; a += tr) {
					for (int b = j; b < C; b += tc) {
						c += ((calc(a, b, a + tr - 1, b + tc - 1) != 0) ? 1 : 0);
					}
				}
				answer = min(c, answer);
			}
		}
		cout << answer << endl;
	}
	return 0;
}
