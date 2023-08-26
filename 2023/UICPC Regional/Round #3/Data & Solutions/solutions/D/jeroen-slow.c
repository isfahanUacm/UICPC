/*
 * @EXPECTED_RESULTS@: TIMELIMIT
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int64_t digsum(int64_t n) {
	int64_t ret = 0;
	while(n>0) {
		ret += n%10;
		n /= 10;
	}
	return ret;
}

void testcase() {
	int64_t a, b, i, ret;
	scanf("%lld %lld\n", &a, &b);
	ret = 0;
	for(i = a; i <= b; i++)
		ret += digsum(i);
	printf("%lld\n", ret);
}

int main() {
	int t;
	scanf("%d\n", &t);
	while(t--) testcase();
	return 0;
}
