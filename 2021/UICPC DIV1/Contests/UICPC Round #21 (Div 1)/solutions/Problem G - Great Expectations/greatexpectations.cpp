#include <bits/stdc++.h>
using namespace std;

#define time asdf

const int N = 55, M = 5050;
int n, m, time[N], loss[N];
double E, prob[N], dp[N][M];

double rec(int i, int j) {
	if (j >= m) return E;
	if (i == n) return 0;
	if (dp[i][j] > 0) return dp[i][j];

	int dt = time[i+1]-time[i];
	double a = min(E, dt + rec(i+1, j+dt));
	double b = min(E, dt+loss[i] + rec(i+1, j+dt+loss[i]));
	return dp[i][j] = min(E, prob[i]*a + (1-prob[i])*b);
}

int main() {
	int len;
	cin >> len >> m >> n;

	for (int i = 0; i < n; i++) {
		cin >> time[i] >> prob[i] >> loss[i];
	}
	time[n] = len;

	double Emin = 0, Emax = 1e10;
	for (int iter = 0; iter < 100; iter++) {
		E = (Emin+Emax)/2;
		memset(dp, 0, sizeof dp);
		(time[0] + rec(0,time[0]) < E ? Emax : Emin) = E;
	}
	cout << fixed << setprecision(20) << E << endl;
}
