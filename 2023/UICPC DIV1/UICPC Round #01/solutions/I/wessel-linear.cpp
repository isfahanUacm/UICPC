#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {

	int n;
	cin >> n;
	std::vector<ll> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i]; // slowest part?
	}
	ll A = a[0]*a[0];
	ll B = 0;
	for (int i = 1; i < n; ++i)
	{
		B += a[i];
	}

	ll mx = A*B;
	for (int k = 1; k < n-1; ++k)
	{
		A += a[k] * a[k];
		B -= a[k];
		mx = max(mx, A*B);
	}

	cout << mx << endl;

	return 0;
}