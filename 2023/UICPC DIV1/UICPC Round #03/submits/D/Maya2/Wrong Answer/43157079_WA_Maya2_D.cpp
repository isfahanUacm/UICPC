#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn  = 2e5 + 10;
int arr1[maxn];
int arr2[maxn];
ll parr1[maxn];
ll parr2[maxn];

int main()
{
	int n;
	ll sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr1[i] >> arr2[i];
	}
	sort(arr1, arr1 + n);
	sort(arr2, arr2 + n);
	parr1[0] = arr1[0];
	parr2[0] = arr2[0];
	for (int i = 0; i < n; i++) {
		parr1[i] = parr1[i - 1] + arr1[i];
		parr2[i] = parr2[i - 1] + arr2[i];
	}
	for (int i = n - 1; i > 0; i--) {
		sum += arr1[i] * i - parr1[i - 1];
		sum += arr2[i] * i - parr2[i - 1];
	}

	cout << sum;

	return 0;
}
