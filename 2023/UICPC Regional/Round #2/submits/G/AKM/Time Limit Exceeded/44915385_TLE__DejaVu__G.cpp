#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	vector<pair<int, int>> arr;
	vector<int> maxes;
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
		maxes.push_back(arr[0].second);
		for (int j = 1; j < m; j++)
		{
			sort(maxes.begin(), maxes.end());
			int min_of_max = maxes[0];
			if (arr[j].second > min_of_max && arr[j].first > arr[j - 1].first)
			{
				maxes[0] = arr[j].second;
			}
			else
			{
				counter++;
				maxes.push_back(arr[j].second);
			}
		}

		cout << counter << endl;
	}


}