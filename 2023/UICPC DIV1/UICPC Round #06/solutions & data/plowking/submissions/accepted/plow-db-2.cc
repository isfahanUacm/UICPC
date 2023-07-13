#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, m;
	cin >> n >> m;

	long long dense = 1;
	while(dense * (dense-1) / 2 + (n - dense) < m)
		dense++;

	long long ans = 0;
	for(long long i=1;i<dense;i++)
		ans += i * (i-1) / 2 + 1;

	for(long long i=0;i<n-dense;i++)
		ans += m-i;

	cout << ans << endl;
}
