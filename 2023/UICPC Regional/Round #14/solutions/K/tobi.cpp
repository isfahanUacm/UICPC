// @EXPECTED_RESULTS@: CORRECT
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
const double eps = 1e-9;

struct P {
	double x[3];
};
P operator+(const P&a,const P&b){
	P ret;
	FOR(i,0,3)ret.x[i]= a.x[i]+b.x[i];
	return ret;
}
P operator-(const P&a,const P&b){
	P ret;
	FOR(i,0,3)ret.x[i]= a.x[i]-b.x[i];
	return ret;
}
double operator*(const P&a,const P&b){
	double ret=0;
	FOR(i,0,3)ret+= a.x[i]*b.x[i];
	return ret;
}
P operator*(const P&a,double b){
	P ret;
	FOR(i,0,3)ret.x[i]= a.x[i]*b;
	return ret;
}
P operator/(const P&a,const P&b){
	P ret;
	FOR(i,0,3)ret.x[i]= a.x[(i+1)%3]*b.x[(i+2)%3]-a.x[(i+2)%3]*b.x[(i+1)%3];
	return ret;
}
double betrag(const P&a) {
	double sum = 0;
	FOR(i,0,3) sum += (a.x[i] * a.x[i]);
	sum = sqrt(sum);
	return sum;
}
P norm(const P&a) {
	P ret;
	double sum = betrag(a);
	FOR(i,0,3) ret.x[i] = a.x[i] / sum;
	return ret;
}

P t[2][3];

double lpi(P start, P end, P auf, P normal) {
	double nenner = (normal * (end - start));
	if (fabsl(nenner) < eps) return -1;
	return (normal * (auf - start)) / nenner;
}

bool tangled(P t1[3], P t2[3]) {
	P normal = (t1[0] - t1[1]) / (t1[0] - t1[2]);
	normal = norm(normal);
	int cnts = 0;
	FOR(i, 0, 3) {
		double alpha = lpi(t2[i], t2[(i+1)%3], t1[0], normal);
		if (alpha < -eps || alpha > 1.+eps) continue;
		P cut = t2[i] + ((t2[(i+1)%3] - t2[i]) * alpha);
		int plus = 0;
		FOR(j, 0, 3) {
			P normal2 = norm(((t1[j] - t1[(j+1)%3]) / normal));
			double dist = normal2 * (t1[j] - cut);
			if (dist < eps) plus++;
		}
		if (plus == 3) cnts++;
		
	}
	return cnts == 1;
}

int main() {
	int numCases;
	cin >> numCases;
	while (numCases --> 0) {
		FOR(i, 0, 2) FOR(j, 0, 3) FOR(k, 0, 3) cin >> t[i][j].x[k];
		cout << ((tangled(t[0], t[1]) || tangled(t[1], t[0])) ? "YES" : "NO") << endl;
	}
	return 0;
}
