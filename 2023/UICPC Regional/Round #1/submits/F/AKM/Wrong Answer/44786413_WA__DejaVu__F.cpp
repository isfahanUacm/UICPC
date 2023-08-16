#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k, n;
	cin >> k >> n;
	set < pair<int, int>> y_p;
	int aim_y = 0, aim_p = 0;
	for (int i = 0; i < k + n - 1; i++)
	{
		int y, p;
		cin >> y >> p;
		if (i == 0)
		{
			aim_y = y;
			aim_p = p;
		}
		y_p.insert(make_pair(y, p));
	}

	set<pair<int, int>> ::iterator it = y_p.begin();
	set<pair<int, int>> ::iterator tmp_it;
	for (int i = 0; i < k - 1; i++)
		it++;
	bool is_win = false;
	int win_year = 0;
	for (; it != y_p.end(); it++)
	{
		if (it->first < aim_y)
		{
			tmp_it = it;
			tmp_it--;
			y_p.erase(it);
			it = tmp_it;
		}
		else if (it->first >= aim_y)
		{
			if (it->second == aim_p)
			{
				is_win = true;
				win_year = it->first;
				break;
			}
			else
			{
				tmp_it = it;
				tmp_it--;
				y_p.erase(it);
				it = tmp_it;
			}
		}
	}
	if (is_win == false)
		cout << "unknown";
	else
		cout << win_year;
}