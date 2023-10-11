// Solution to: Safe Racing
// By: Raymond van Bommel

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>

#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <string>

#include <iostream>
#include <sstream>

#include <utility>
#include <functional>
#include <limits>
#include <numeric>
#include <algorithm> 

using namespace std;

int L, S;

const long long Modulus = 123456789;

long long dp[1234567]; // dp[d] = number of ways to put marshalls on the first d decametres such that there are marshalls at the start and at d

void DP() {
	long long sumoflastSvalues = 1;
	dp[0] = 1;
	for (int d = 1; d <= L; d++) {
		dp[d] = sumoflastSvalues;
		sumoflastSvalues += dp[d] + Modulus;
		if (d-S >= 0)
			sumoflastSvalues -= dp[d-S];
		sumoflastSvalues %= Modulus;
	}
}

void doit() {
	cin >> L >> S;
	DP();	// Execute DP
	long long ans = 0;
	for (int l = 1; l <= S; l++) {
		ans += dp[L-l] * l; // Factor l+1 is for the possible rotations to the left.
		ans %= Modulus;
	}
	cout << ans << '\n';
}

int main () {
	int T = 1;
	//cin >> T;
	for (int t = 1; t <= T; t++) {
		doit();
	}
	return 0;
}
