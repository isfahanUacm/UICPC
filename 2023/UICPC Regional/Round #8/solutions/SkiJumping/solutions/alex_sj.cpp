// @EXPECTED_RESULTS@: CORRECT
#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

double j,p,H,L,v0;
double h(double l){
	if (l < 0) return H;
	if (l < L*0.5) return H * (1.0 - 2.0 * pow(l/L,2));
	if (l < L) return 2.0 * H * pow(l/L - 1.0, 2);
	return 0.0;
}
double hdl(double l){
	if (l < 0) return 0.0;
	if (l < L * 0.5) return -4.0 * H * l / pow(L,2);
	if (l < L) return 4.0 * H * (l / L - 1.0) / L;
	return 0.0;
}
double f(double l){
	return -9.81 * 0.5 * pow(l/v0,2) + H + p;
}
double fdl(double l){
	return -9.81 * pow(1.0/v0, 2) * l;
}
int main() {
	int tc;
	cin >> tc;
	while(tc--){
		cin >> j >> p >> H >> L;
		v0 = max(sqrt(2.0 * 9.81 * j), 1e-50);
		double hi = sqrt((H + p) * pow(v0,2) * 2.0 / 9.81), lo = 0.0;
		FOR(i,0,50){
			double mid = lo + 0.5 * (hi - lo);
			if(f(mid) > h(mid))lo = mid;
			else hi = mid;
		}
		double l = lo + 0.5 * (hi - lo);
		double vLanding = max(sqrt(2.0 * 9.81 * (j + p + H - h(l))), 1e-50);
		double w = abs(atan(fdl(l)) - atan(hdl(l))) * 90.0 / acos(0.0);
		printf("%.8lf %.8lf %.8lf\n",l,vLanding,w);
	}
	return 0;
}
