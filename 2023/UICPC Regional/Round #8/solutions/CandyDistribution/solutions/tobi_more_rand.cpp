// @EXPECTED_RESULTS@: CORRECT

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

pair<ll, pair<ll, ll> > eea(ll a, ll b) {
    if (b == 0) return make_pair(a, make_pair(1, 0));
    pair<ll, pair<ll, ll> > p = eea(b, a % b);
    ll s = p.second.first, t = p.second.second;
    return make_pair(p.first, make_pair(t, s - t * (a / b)));
}

int main(int argc, char **argv) {
	int numCases;
	scanf("%d", &numCases);

	while (numCases --> 0) {
		long long K, C;
		scanf("%lld%lld", &K, &C);
		if (C == 1) {
			printf("%lld\n", K + 1);
			continue;
		} else if (K == 1) {
			puts("1");
			continue;
		}

		pair<ll, pair<ll, ll> > extEuclid = eea(C, K);

		if (extEuclid.first != 1) {
			puts("IMPOSSIBLE");
		} else {
			ll inverse = (extEuclid.second.first + K) % K;
			ll more = inverse + K*C * ((rand() % 1000) + 1);
			if (more > 0 && more <= 1000000000) {
				printf("%lld\n", more);
			} else {
				printf("%lld\n", inverse);
			}
		}
	}

	return 0;
}
