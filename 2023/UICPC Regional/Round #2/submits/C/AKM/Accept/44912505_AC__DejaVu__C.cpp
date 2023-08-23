#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	vector<int> arr;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		arr.clear();
		for (int k = 0; k < n; k++)
		{
			int p;
			cin >> p;
			arr.push_back(p);
		}
		sort(arr.begin(), arr.end());
		cout << 2 * (arr[arr.size() - 1] - arr[0]) << endl;
	}
}