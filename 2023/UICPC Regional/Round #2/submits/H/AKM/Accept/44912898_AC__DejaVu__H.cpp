#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr;

	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		arr.push_back(p);
	}
	sort(arr.begin(), arr.end(), greater<int>());

	long long res = 0;
	for (int i = 2; i < arr.size(); i += 3)
	{
		res += arr[i];
	}

	cout << res;
}