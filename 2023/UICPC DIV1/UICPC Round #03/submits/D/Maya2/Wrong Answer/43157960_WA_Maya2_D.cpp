#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn  = 2e5 + 10;
ll arr1[maxn];
ll arr2[maxn];
ll parr1[maxn];
ll parr2[maxn];
pair<ll, ll> ar[maxn];


int main()
{
	int n;
	ll sum = 0;
	cin >> n;
	ll a,b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		ar[i] = {a, b};
	}
	sort(ar, ar + n);
	n = unique(ar, ar + n) - ar;
	for (int i = 0; i < n; i++) {
		arr1[i] = ar[i].first;
		arr2[i] = ar[i].second;
	}
	sort(arr1, arr1 + n);
	sort(arr2, arr2 + n);
	parr1[0] = arr1[0];
	parr2[0] = arr2[0];
	for (int i = 1; i < n; i++) {
		parr1[i] = parr1[i - 1] + arr1[i];
		parr2[i] = parr2[i - 1] + arr2[i];
	}
	for (int i = n - 1; i > 0; i--) {
		sum += abs(arr1[i] * i - parr1[i - 1]);
		sum += abs(arr2[i] * i - parr2[i - 1]);
	}

	cout << sum;

	return 0;
}
