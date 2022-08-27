#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;


int main()
{
	int n;
	cin >> n;

	vector<pair<pair<int, int>, pair<int, int>>> slv;
	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		slv.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
	}
	int q;
	cin >> q;

	while (q--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		bool f = true;
		
		for (auto t : slv)
		{
			double m, m1;
			if (t.second.first - t.first.first == 0 && x2 - x1==0)
			{
				cout << "different\n";
				f = false;
				break;
			}
			else if (t.second.first - t.first.first == 0 || x2 - x1 == 0)
			{
				break;
			}
			else
			{
				m = 1.0 * (t.second.second - t.first.second) / (t.second.first - t.first.first);
				m1 = 1.0 * (y2 - y1) / (x2 - x1);
			}

			if (m1 == m)
			{
				cout << "different\n";
				f = false;
				break;
			}
		}

		if (f) cout << "same\n";
	}
}