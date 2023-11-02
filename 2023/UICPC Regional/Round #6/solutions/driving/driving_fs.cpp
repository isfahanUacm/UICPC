#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int p, num, d;
	vector<int> dist;
	cin >> num >> p;
	for(int i = 0; i < num; ++i)
	{
		cin >> d;
		dist.push_back(d);
	}
	sort(dist.begin(), dist.end());

	int ret = 0;
	for(int n = 0; n < dist.size(); ++n)
		ret = max(ret, p*(1+n) - dist[n]);
	cout << ret+dist[0] << endl;
	return 0;
}
