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

# define M_PIl          3.141592653589793238462643383279502884L

int main()
{
	int n;
	cin >> n;

	map <char, int> slv;
	slv.insert(make_pair(' ', 0));
	slv.insert(make_pair('\'', 1));

	for (int i = 2; i < 28; i++)
	{
		slv.insert(make_pair(char(i + 65 - 2), i));
	}

	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string s;
		getline(cin, s);

		long double res = 0.0;
		char lastC = s[0];
		for (int j = 0; j < s.length(); j++)
		{
			int t1 = slv[s[j]] - slv[lastC];
			int t2 = slv[lastC] - slv[s[j]];

			if (t1 < 0)
			{
				t1 += 28;
				if (t1 < t2)
				{
					res += (t1) * 60.0 * M_PIl / 28.0 / 15.0;
					res += 1;
				}
				else
				{
					res += (t2) * 60.0 * M_PIl / 28.0 / 15.0;
					res += 1;
				}
			}
			else
			{
				t2 += 28;
				if (t1 < t2)
				{
					res += (t1) * 60.0 * M_PIl / 28.0 / 15.0;
					res++;
					
				}
				else
				{
					res += (t2) * 60.0 * M_PIl / 28.0 / 15.0;
					res += 1;
				}
			}
			
			lastC = s[j];
		}

		cout << setprecision(8) << fixed << showpoint << res << "\n";
	}
}