#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int t;
	cin >> t;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int sum = 0;
	bool is_all = false;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		if (sum > t)
		{
			cout << i;
			is_all = true;
			break;
		}
	}
	if (is_all == false)
		cout << n;


}