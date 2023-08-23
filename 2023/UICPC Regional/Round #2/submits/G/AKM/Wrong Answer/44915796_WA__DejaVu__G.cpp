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
	multiset<int> maxes;
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

		int counter = 1;
		maxes.insert(arr[0].second);
		for (int j = 1; j < m; j++)
		{
			int min_of_max = *maxes.begin();
			if (arr[j].second > min_of_max && arr[j].first > arr[j - 1].first)
			{
				maxes.erase(maxes.begin());
				maxes.insert(arr[j].second);
			}
			else
			{
				counter++;
				maxes.insert(arr[j].second);
			}
		}

		cout << counter << endl;
	}


}