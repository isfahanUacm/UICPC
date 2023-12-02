// O(nk)

#include <iostream>

using namespace std;

typedef long long ll;

#define M 1000000007

int n, k;
ll dp[2][11111];

int main() {
	cin >> n >> k;
	if (k > n) {
		cout << "0\n";
		return 0;
	}
	for (int i = 1; i <= n; i++) dp[0][i] = k*(k-1);
	for (int c = 3; c <= k; c++) {
		int a = c%2;
		int b = 1-a;
		for (int i = 1; i < c; i++) {
			dp[a][i] = 0;
		}
		for (int i = c; i <= n; i++) {
			dp[a][i] = (dp[a][i-1]*(c-1)+dp[b][i-1]*(k-c+1))%M;
		}
	}
	cout << dp[k%2][n] << "\n";
}
