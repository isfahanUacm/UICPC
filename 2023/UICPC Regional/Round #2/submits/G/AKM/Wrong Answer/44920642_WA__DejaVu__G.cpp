#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	vector<pair<int, int>> arr;
	multiset<pair<int, int>> maxes;
	for (int i = 0; i < t; i++)
	{
		arr.clear();
		maxes.clear();
		int m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			int w, h;
			cin >> w >> h;
			arr.push_back(make_pair(w, h));
		}
		sort(arr.begin(), arr.end());

		if (m == 1)
		{
			cout << 1 << endl;
			continue;
		}

		int counter = 1;
		int maxes_size = maxes.size();
		int equal_s = 2;
		if (arr[1].first != arr[0].first)
		{
			maxes.insert(make_pair(arr[0].second, arr[0].first));
			equal_s = 1;
		}
		for (int j = 1; j < m; j++)
		{
			//if (equal_s >= 2)
			//{
			if (maxes.size() == 0)
			{
				counter++;
				if (j + 1 < m)
					if (arr[j + 1].first != arr[j].first)
					{
						for (int k = j; k > j - equal_s; k--)
						{
							maxes.insert(make_pair(arr[k].second, arr[k].first));
						}
						equal_s = 1;
					}
					else
					{
						equal_s++;
						continue;
					}
				else
					continue;
			}
			else
			{
				int min_of_max = (*maxes.begin()).first;
				if (arr[j].second > min_of_max)
				{
					maxes.erase(maxes.begin());
					if (j + 1 < m)
						if (arr[j + 1].first != arr[j].first)
						{
							for (int k = j; k > j - equal_s; k--)
							{
								maxes.insert(make_pair(arr[k].second, arr[k].first));
							}
							equal_s = 1;
						}
						else
						{
							equal_s++;
							continue;
						}
					else
						continue;
				}
				else
				{
					counter++;
					if (j + 1 < m)
						if (arr[j + 1].first != arr[j].first)
						{
							for (int k = j; k > j - equal_s; k--)
							{
								maxes.insert(make_pair(arr[k].second, arr[k].first));
							}
							equal_s = 1;
						}
						else
						{
							equal_s++;
							continue;
						}
					else
						continue;
				}
			}
			//}
		}

		cout << counter << endl;
	}


}