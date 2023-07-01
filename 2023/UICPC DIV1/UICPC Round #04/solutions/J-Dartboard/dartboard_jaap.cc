/*
 * Solution for NCPC 2013 problem "Dartboard" by Jaap Eldering
 * Complexity: O(1)
 */

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

double eye_r, bull_r, double_in_r, double_out_r, triple_in_r, triple_out_r;
double sigma;

// Which integrated distribution to use
#define INTG normal_intg

double normal_intg(double r)
{
	return -exp(-(r*r)/(2*sigma*sigma));
}

double uniform_intg(double r)
{
	double r1 = min(r,sigma)/sigma;
	return r1*r1;
}

const double eye_score  = 50;
const double bull_score = 25;
const double avgn_score = 10.5;

double expect()
{
	return  eye_score*(INTG(eye_r)        - INTG(0.0))
	    +  bull_score*(INTG(bull_r)       - INTG(eye_r))
	    +  avgn_score*(INTG(double_out_r) - INTG(bull_r))
	    +2*avgn_score*(INTG(triple_out_r) - INTG(triple_in_r))
	    +  avgn_score*(INTG(double_out_r) - INTG(double_in_r));
}

int main()
{
	cin >> eye_r >> bull_r
		>> triple_in_r >> triple_out_r
		>> double_in_r >> double_out_r;

	cin >> sigma;

	double res = expect();
	cout << setprecision(10) << res << endl;

	return 0;
}
