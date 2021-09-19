#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll a, b, s;
const int siz = 18, S = 136;
ll dp[siz][S];

void init(){
	for (int i = 0; i < siz; i++)
		for (int j = 0; j < S; j++)
			dp[i][j] = 0;
	dp[0][0] = 1;
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	for (int i = 2; i < siz; i++)
		for (int j = 0; j < S;j++)
			for (int k = 0; k < 10 && j - k >= 0; k++)
				dp[i][j] += dp[i-1][j-k];
}

ll cdp(ll n, int s){
    if (n == 0 && s == 0)
        return 1;
    if (s < 0 || n == 0)
        return 0;
	ll sum = 0, m = n;
	int lastd, len = 0;
	while(m){
		lastd = m % 10;
		m /= 10;
		len++;
	}
	if (len == 1){
		if (s <= n)
            return 1;
		else
            return 0;
	}
	for (int i = 0; i < lastd && s - i >= 0; i++)
		sum += dp[len-1][s-i];
	return (sum + cdp(n - lastd * pow(10, len - 1),s - lastd));
}

ll first(){
	ll lo = a, hi = b, mid;
	while(lo != hi){
		mid = (lo+hi+1)/2;
		if (cdp(mid, s) - cdp(lo, s))
			hi = mid-1;
		else
			lo = mid;
	}
	return lo + 1;
}

int main(){
	init();
	cin >> a >> b >> s;
	cout << cdp(b, s) - cdp(a - 1, s) << endl;
	cout << first() << endl;
    return 0;
}
