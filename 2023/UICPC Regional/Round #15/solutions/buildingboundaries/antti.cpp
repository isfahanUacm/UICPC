#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll best;

void check(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll w1 = x1+x2+x3;
	ll h1 = max(max(y1,y2),y3);
	ll area = w1*h1;
	if (y1 >= y2) {
		ll w2 = max(x1+x2,x3);
		ll h2 = y1+y3;
		area = min(area,w2*h2);
	}
	best = min(best,area);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		best = 5e18;
		ll a[4], b[4];
		cin >> a[1] >> b[1] >> a[2] >> b[2] >> a[3] >> b[3];
		int p[] = {1,2,3};
		do {
			for (int k = 0; k < (1<<3); k++) {
				ll x[4], y[4];
				for (int i = 1; i <= 3; i++) {
					x[i] = a[p[i-1]];
					y[i] = b[p[i-1]];
				}
				if (k&1) swap(x[1],y[1]);
				if (k&2) swap(x[2],y[2]);
				if (k&4) swap(x[3],y[3]);
				check(x[1],y[1],x[2],y[2],x[3],y[3]);
			}
		} while (next_permutation(p,p+3));
		cout << best << "\n";
	}
}
