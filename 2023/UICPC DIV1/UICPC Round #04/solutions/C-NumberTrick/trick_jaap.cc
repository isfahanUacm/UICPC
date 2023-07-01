/*
 * Solution for NCPC 2013 problem "Number trick" by Jaap Eldering
 * Complexity: O(1)
 */

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int x, xd = 1; // X as fraction, xd power 10 denominator
	char c;

	cin >> x >> c;
	if ( x>=10 ) {
		cout << "No solution\n";
		return 0;
	}
	if ( c=='.' ) {
		while ( cin >> c && isdigit(c) ) {
			x *= 10;
			xd *= 10;
			x += c - '0';
		}
	}

	int found = 0;
	long long p = 1;
	for(int k=1; k<9; k++, p*=10) {
		for(int yk=1; yk<10; yk++) {
			long long yr = yk*(x*p-xd);
			long long d = 10*xd - x;
			if ( yr%d==0 && (yr /= d)<p ) {
				long long y = yk*p + yr;
				cout << y << endl;
				found = 1;
			}
		}
	}

	if ( !found ) cout << "No solution\n";

	return 0;
}
