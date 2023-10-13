// @EXPECTED_RESULTS@: CORRECT

// all.in is too big and my solution prints too many digits
// either split up all.in or increase the output limit:
// -rw-r--r-- 1 jakob jakob 5708888 Jun 14 18:19 all.out     <- sample solution output
// -rw-r--r-- 1 jakob jakob 8770902 Jun 15 16:19 my.out      <- output of my solution
// 10 MB should be sufficient...

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip> 
using namespace std;

	static const double eps = 1e-8;
	static const double g = 9.81;
	static double j;
	static double p;
	static double H;
	static double L;
	static double v0;
	

	static double f(double l) {
		return H + p - 0.5 * g * l * l / (v0 * v0);
	}

	static double ftick(double l) {
		return - g*l/(v0*v0);
	}

	static double h(double l) {
		if(l < 0)   return H;
		if(l < L/2) return H * (1 - 2 * l*l / (L*L) );
		if(l < L)   return 2 * H * (l/L - 1) * (l/L - 1);
		return 0;
	}
	
	static double htick(double l) {
		if(l < 0) return 0;
		if(l < L/2) return - H * 4 * l / (L*L);
		if(l < L) return 4 * H * (l/L - 1) / L;
		return 0;
	}

	static double v(double l) {
		double t = l / v0;
		double vv = 9.81 * t;
		return sqrt(vv * vv + v0 * v0);
	}

	int main() {
		int ntc;
		cin >> ntc;
		while(ntc-- != 0) {
			double min = 0;
			double max = 10;
			cin >> j;
			cin >> p;
			cin >> H;
			cin >> L;
			v0 = sqrt(9.81 * j * 2);
			while(f(max) >= 0) {
				max *= 2;
			}
			while(max-min > eps){
				double tmp = (max+min)/2;
				if(f(tmp) > h(tmp)){
					min = tmp;
				} else {
					max = tmp;
				}
			}
			double eq = (max+min)/2;
			double angleh = atan(htick(eq));
			double anglej = atan(ftick(eq));
			cout << setprecision(8) << eq << " "<< v(eq) << " " << abs(angleh - anglej) * 180 / M_PI << endl;
		}
	}


