#include <bits/stdc++.h>
using namespace std;

#define ll int
#define pll pair<ll, ll>

struct Line {
	ll r1, r2, t;
};

struct Circle {
	ll t1, t2, r;
};

bool intersect(ll s1, ll e1, ll s2, ll e2) { // s1 <= e1 - s2 <= e2
	return s2 <= e1 && e2 >= s1 && s1 <= e1 && s2 <= e2;
}

bool contains(ll s, ll e, ll n) { // s1 <= e1 - s2 <= e2
	return (s <= e && s <= n && n <= e) || (s > e && ~(e < n&& n < s));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, t;
	cin >> t;
	while (t--) {
		char c;
		cin >> n;

		vector<Line> lines;
		vector<Circle> circles;
		ll rings = 0;

		while (n--) {
			cin >> c;

			if (c == 'C') {
				Circle temp;
				rings++;
				cin >> temp.r >> temp.t2 >> temp.t1;
				circles.push_back(temp);
			} else {
				Line temp;
				cin >> temp.r1 >> temp.r2 >> temp.t;
				lines.push_back(temp);
			}
		}

		sort(circles.begin(), circles.end(), [](const Circle& c1, const Circle& c2) {
			return c1.r > c2.r;
			});

		ll rads[rings];
		vector<ll> walls[rings - 1];

		for (ll i = 0;i < rings;i++) { rads[i] = circles[i].r; }

		for (Line x : lines) {
			for (ll i = 0;i < rings - 1;i++) {
				if (x.r1 <= rads[i] && x.r2 >= rads[i + 1]) {
					walls[i].push_back(x.t);
				} else if (x.r2 < rads[i + 1]) {
					break;
				}
			}
		}

		bool possible = true;
		for (ll i = 0;i < rings - 1;i++) {
			ll path = false;

			Circle enter = circles[i];
			Circle target = circles[i + 1];

			// cout << "Ring #" << i << endl;
			// cout << "Enter: " << enter.t1 << " " << enter.t2 << endl;
			// cout << "Target: " << target.t1 << " " << target.t2 << endl;
			// cout << "Walls: ";
			// for (auto x : walls[i]) { cout << x << " "; }
			// cout << endl;

			bool seen_enter = false, seen_target = false;
			for (ll d = enter.t2;d != enter.t2 - 1;d = (d + 1) % 360) {
				if (!seen_enter && contains(enter.t1, enter.t2, d)) {
					seen_enter = true;
					// cout << "1) enter at " << d << endl;
				}
				if (!seen_target && contains(target.t1, target.t2, d)) {
					seen_target = true;
					// cout << "1) target at " << d << endl;
				}

				for (auto x : walls[i]) {
					if (d == x) {
						// cout << "1) Reset due to wall " << x << endl;
						seen_enter = false;
						seen_target = false;
						break;
					}
				}

				if (seen_enter && seen_target) {
					// cout << "1) Path found in " << d % 360 << endl;
					path = true;
					break;
				}
			}

			for (ll d = enter.t1;d != enter.t1 + 1;d = (d - 1 + 360) % 360) {
				if (!seen_enter && contains(enter.t1, enter.t2, d)) {
					seen_enter = true;
					// cout << "1) enter at " << d << endl;
				}
				if (!seen_target && contains(target.t1, target.t2, d)) {
					seen_target = true;
					// cout << "1) target at " << d << endl;
				}

				for (auto x : walls[i]) {
					if (d == x) {
						// cout << "1) Reset due to wall " << x << endl;
						seen_enter = false;
						seen_target = false;
						break;
					}
				}

				if (seen_enter && seen_target) {
					// cout << "1) Path found in " << d % 360 << endl;
					path = true;
					break;
				}
			}

			if (!path) {
				possible = false;
				break;
			}
		}

		cout << (possible ? "YES" : "NO") << endl;

		// 			if (
		// 				intersect(enter.t1, enter.t2, target.t1, target.t2) ||
		// 
		// 				intersect(enter.t1 + 360, enter.t2 + 360, target.t1, target.t2) ||
		// 
		// 				intersect(enter.t1, enter.t2, target.t1 + 360, target.t2 + 360)
		// 				) { // direct path
		// 				continue;
		// 
		// 			} else {
		// 
		// 
		// 				// possible = false;
		// 				// break;
		// 			}
	}
}