/*
 * Solution for NCPC 2013 problem "Dartboard" by Jaap Eldering
 * Using numerical integration with midpoint rule.
 */

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

double ring_rad[6];
double ring_score[6] = {50, 25, 10.5, 3*10.5, 10.5, 2*10.5};
double sigma, sigma2;

double normaldist(double r)
{
	double x = -(r*r)/(2*sigma2);
	if ( x<-1000 ) return 0;
	return (r/sigma2)*exp(x);
}

const int nsteps = 5000000;
const double nsigma = 5;

double expect()
{
	double max_r = min(nsigma*sigma,ring_rad[5]);
	double dstep = max_r / nsteps, res = 0;

	double f1, f2;
	for(int i=0; i<6; i++) {
		double r, r0 = (i==0 ? 0 : ring_rad[i-1]);
		f1 = normaldist(r0);
		for(r=r0; r<ring_rad[i]; r+=dstep) {
			f2 = normaldist(r+dstep);
			res += dstep*ring_score[i]*(f1+f2+4*normaldist(r+dstep/2))/6;
			f1 = f2;
			if ( r>max_r+dstep ) return res;
		}
		r = max(r0,r-dstep);
		res += (ring_rad[i]-r)*ring_score[i]*
		    (normaldist(r)+normaldist(ring_rad[i])+4*normaldist((r+ring_rad[i])/2))/6;
	}

	return res;
}

int main()
{
	for(int i=0; i<6; i++) cin >> ring_rad[i];

	cin >> sigma;

	sigma2 = sigma*sigma;

	double res = expect();
	cout << setprecision(10) << res << endl;

	return 0;
}
