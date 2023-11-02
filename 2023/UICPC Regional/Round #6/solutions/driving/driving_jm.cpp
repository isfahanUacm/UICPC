#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, p, x, y, first;
	cin >> n >> p;
	vector<int> dist(n);
	for(int i=0;i<n;i++) cin >> dist[i];
	sort(dist.begin(), dist.end());
	first = dist[0];
	y = first - p;
	for(int i=1;i<n;i++) {
		x = dist[i] - (i+1) * p;
		if (x < y) y = x;
	}
	cout << first - y << endl;
	
	return 0;
}
