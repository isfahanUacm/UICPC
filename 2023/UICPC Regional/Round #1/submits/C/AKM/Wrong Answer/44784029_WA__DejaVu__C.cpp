#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	string* arr = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		bool is_won = true;
		for (int j = 1; j < arr[i].size(); j++)
		{
			if (arr[i][j] == 'C' && arr[i][j - 1] == 'D')
			{
				is_won = false;
				break;
			}
		}

		if (is_won == true)
			counter++;
	}

	cout << counter;
}