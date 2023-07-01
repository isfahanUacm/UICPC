/*
 * Solution for NCPC 2013 problem "Vegetables" by Jaap Eldering
 * Complexity: O(n^3), optimized, not sure if a testcase exhibiting
 *                     worst case behaviour can be created.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	double T;
	int n;

	cin >> T >> n;

	vector<double> w(n);
	for(int i=0; i<n; i++) cin >> w[i];

	int best = 501;
	for(int i=0; i<n; i++) {
		for(int c=0; c<best; c++) {
			double maxsize = w[i]/(c+1);
			double minsize = maxsize*T;

			int ncuts = c;
			for(int j=0; j<n; j++) {
				if ( j==i ) continue;
				int c1 = (int)ceil(w[j]/maxsize) - 1;
				if ( w[j]/(c1+1)<minsize ) goto next;
				ncuts += c1;
				if ( ncuts>=best ) goto next;
			}

			if ( ncuts<best ) best = ncuts;
		  next:
			while ( 0 );
		}
	}

	if ( best>=500 ) {
		cout << "too large: " << best << endl;
		return 1;
	}

	cout << best << endl;

	return 0;
}
