#include <iostream>
#include <functional>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r;
	double s;
	while (cin >> r >> s)
	{
		s += 0.16;
		double m = r * s / 0.067;
		double v = sqrt(m);
		cout << round(v) << endl;
	}
}