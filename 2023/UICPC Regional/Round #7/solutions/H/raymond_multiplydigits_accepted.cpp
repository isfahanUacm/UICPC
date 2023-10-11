// Solution to: Multiplying digits
// By: Raymond van Bommel
#include <iostream>
#include <cassert>
#include <climits>
#include <map>

using namespace std;

unsigned long long b;
const unsigned long long INFINITY = ULLONG_MAX-1;
int maxdepth = -1;
map<unsigned long long, unsigned long long> solcache;
map<unsigned long long, unsigned long long> solmaxdigit;

bool possible (unsigned long long n) {
	for (int i = b-1; i >= 2; i--)
		while ((n % i) == 0) {
			n /= i;
			maxdepth++;
		}
	return (n == 1);
}

unsigned long long sol (unsigned long long n, unsigned long long maxdigit, int depth) {
	unsigned long long ret = INFINITY;
	unsigned long long mindigit = 1;
	if (solcache.find(n) != solcache.end())	{// Optimisation 1: memoisation
		if (solmaxdigit[n] >= maxdigit)
			return solcache[n];
		else {
			ret = solcache[n];
			mindigit = solmaxdigit[n]+1;	
		}	
	}
	unsigned long long maxpossible = 1;
	for (int i = depth; i <= maxdepth; i++) {	// Optimisation 2B: check if it is still feasible to get n
		for (unsigned long long j = 2; j <= maxdigit; j *= 2) {
			if (maxpossible*j > INFINITY/2) {
				maxpossible = INFINITY;
				break;
			}
		}
		if (maxpossible == INFINITY)
			break;
		maxpossible *= maxdigit;
	}
	if (n < b) {	// Optimisation 2A: keep track of the number of blocks
		maxdepth = depth;
		return n;	
	}
	if ((depth > maxdepth) || (maxpossible < n))
		return INFINITY/b - b;	
	for (unsigned long long i = maxdigit; (i*i >= b) && (i >= mindigit); i--)	// Optimisation 3: all digits except the last one have size >= sqrt(B)
		if ((n % i) == 0) {
			bool gofurther = false;
			for (unsigned long long j = 2; j*i < b; j++)	// Optimisation 4: if digit j*i if possible, do not try digit i
				if ((n % (i*j) == 0) && (j*i < b)) {
					gofurther = true;
					break;
				}
			if (gofurther)
				continue;
			unsigned long long num = sol(n/i, i, depth+1);
			for (unsigned long long j = 1; j <= b; j *= 2)
				if (j*num > INFINITY/2) {
					num = INFINITY/b - b;
					break;
				}
			ret = min(ret, b*num + i);				
		}	
	if (ret < INFINITY/2 + 2) {
		solcache[n] = ret;
		solmaxdigit[n] = maxdigit;
		return ret;		
	}
	else
		return INFINITY/b - b;
}

int main () {
	unsigned long long n;
	cin >> b >> n;
	if (!possible(n)) {
		cout << "impossible\n";
		return 0;
	}
	cout << sol(n,b-1,0) << "\n";
	return 0;
}



