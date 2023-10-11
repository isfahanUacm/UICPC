// Try a bunch of high-order roots of q and check if prime.
// 
// At most 8 of these roots are integers (case q = 2^24), so we end up checking
// only a few numbers for being prime.

#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

const long long MIN_Q = 1;
const long long MAX_Q = 1000000000; // 10^9

const long double epsilon = 1e-5L;

bool isprime(long long p) {
	if (p <= 1) return false;
	for (long long q = 2; q * q <= p; q++) {
		if (p % q == 0) return false;
	}
	return true;
}

int main() {
	long long q;
	cin >> q;
	assert(q >= MIN_Q && q <= MAX_Q);
	for (long double k = 1; k < 100; k += 1.0L) {
		long double candidate = pow((long double) q, 1.0L / k);
		if (abs(candidate - round(candidate)) > epsilon) continue;
		long long p = llround(candidate);
		long double reconstruction = pow((long double) p, k);
		if (abs(reconstruction - q) > epsilon) continue;
		cerr << " attempting k = " << k << endl;
		if (isprime(p)) {
			cout << "yes" << endl;
			return 0;
		}
	}
	cout << "no" << endl;
	return 0;
}
