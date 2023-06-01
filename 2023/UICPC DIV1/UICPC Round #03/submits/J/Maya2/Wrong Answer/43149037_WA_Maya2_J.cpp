#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int cope[101];
int dis[1002];
int disc[102];

int main()
{
	int n, l, p, mx = 0;
	cin >> n >> l >> p;
	for (int i = 0; i < p; i++) cin >> dis[i];
	disc[0] = l / 2;
	for (int i = 0; i < n; i++) disc[i] = (l * i) + (l / 2);
	int z;
	for (int i = 0; i < p; i++) {
		int mn = 1e9;
		for (int j = 0; j < n; j++) {
			if (abs(dis[i] - disc[j]) < mn) {
				z = j;
				mn = abs(dis[i] - disc[j]);
			}
		}
		cope[z]++;
		mx = max(mx, mn);
	}
	cout << mx << '\n';
	cout << *max_element(cope, cope + n);

	return 0;
}

	
