// @EXPECTED_RESULTS@: CORRECT
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <float.h>

using namespace std;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
const double eps = 1e-9;

int numCases, numForts, numLinks, attack, s, t, N;
double p, u[100];
bool conn[100][100];
struct M { double a[100][100]; };
M m;

M operator*(M A, M B) {
    M R = {0};
    FOR(i, 0, N) FOR(j, 0, N) FOR(k, 0, N) {
        R.a[i][j] = A.a[i][k] * B.a[k][j] + R.a[i][j];
    }
    return R;
}

M pow(M A, int exp) {
	M R = {0};
	FOR(i, 0, N) R.a[i][i] = 1;
	while (exp) {
		if (exp % 2) R = R * A;
		A = A * A;
		exp /= 2;
	}
	return R;
}

int main() {
	cin >> numCases;
	while (numCases --> 0) {
		cin >> numForts >> numLinks >> attack;
		N = numForts;
		FOR(i, 0, numForts) {
			cin >> u[i];
			FOR(j, 0, numForts) {
				m.a[i][j] = 0.;
				conn[i][j] = false;
			}
			m.a[i][i] = 1.;
		}
		FOR(i, 0, numLinks) {
			cin >> s >> t >> p;
			assert(m.a[s][t] == 0);
			m.a[s][t] = p;
			m.a[s][s] -= p;
			conn[s][t] = conn[t][s] = true;
			assert(m.a[s][s] >= -eps);
		}
		double res[numForts];
		if (attack > 0) {
			m = pow(m, attack);
			FOR(i, 0, numForts) {
				res[i] = 0.;
				FOR(j, 0, numForts) res[i] += m.a[j][i] * u[j];
			}
		} else {
			FOR(i, 0, numForts) res[i] = u[i];
		}
		double best = DBL_MAX;
		FOR(i, 0, numForts) {
			double tmp = res[i];
			FOR(j, 0, numForts) if (conn[i][j]) tmp += res[j];
			best = min(best, tmp);
		}
		cout << setprecision(15) << best << endl;
	}
	return 0;
}
