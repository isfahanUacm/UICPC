#include <cassert>
#include <iostream>

using namespace std;

const int MIN_Q = 1;
const int MAX_Q = 1000000000; // 10^9

bool isPrimePower(long long q) {
	// Corner case:
	if (q == 1) {
		return false;
	}
	
	for (long long p = 2; p * p <= q; p++) {
		if (q % p == 0) {
			// Least divisor must be prime.
			// All we have to do is check if q is a power of p.
			while (q % p == 0) {
				q /= p;
			}
			return q == 1;
		}
	}
	
	// Apparently, q is already prime.
	return true;
}

int main() {
	int q;
	cin >> q;
	assert(q >= MIN_Q && q <= MAX_Q);
	cout << (isPrimePower(q) ? "yes" : "no") << endl;
	return 0;
}
