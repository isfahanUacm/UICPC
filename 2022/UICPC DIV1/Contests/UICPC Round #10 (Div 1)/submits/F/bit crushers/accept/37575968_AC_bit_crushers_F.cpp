#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, m, t;
	cin >> t;
	while (t--) {
		cin >> n >> m;

		// n , m-2
		// n-2 , m
		// n-1 , m-1

		// n-2 n m-1
		// n-1 m-2 m

		set<ll> values;

		if ((n % 2 == 0 && (m - 1) % 2 == 0) || (m % 2 == 0 && (n - 1) % 2 == 0))
			values.insert(2);

		ll a = gcd(n, m - 2);
		ll b = gcd(n - 2, m);
		ll c = gcd(n - 1, m - 1);

		values.insert(1);
		values.insert(a);
		values.insert(b);
		values.insert(c);

		for (ll i = 2;i * i <= a;i++) if (a % i == 0) {
			values.insert(i);
			values.insert(a / i);
		}

		for (ll i = 2;i * i <= b;i++) if (b % i == 0) {
			values.insert(i);
			values.insert(b / i);
		}

		for (ll i = 2;i * i <= c;i++) if (c % i == 0) {
			values.insert(i);
			values.insert(c / i);
		}


		vector<ll> s;
		for (auto x : values) { s.push_back(x); }
		sort(s.begin(), s.end());

		cout << s.size();

		for (auto x : s) cout << " " << x;
		cout << endl;
	}
}