#include <iostream>
using namespace std;

int main()
{
	int m, n, k;
	cin >> m >> n >> k;
	int** arr = new int* [m];
	for (int i = 0; i < m; i++)
		arr[i] = new int[n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	int* zero_count = new int[m];
	bool* is_zero = new bool[n];
	for (int j = 0; j < n; j++)
		is_zero[j] = false;

	for (int kako = 0; kako < k; kako++)
	{
		int max_zero_count = -1;
		int max_zero_row;
		for (int i = 0; i < m; i++)
		{
			zero_count[i] = 0;
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == 0 && is_zero[j] == false)
				{
					zero_count[i]++;
				}
			}
			if (zero_count[i] > max_zero_count)
			{
				max_zero_count = zero_count[i];
				max_zero_row = i;
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (arr[max_zero_row][j] == 0)
			{
				is_zero[j] = true;
			}
		}
	}

	bool is_posible = true;
	for (int j = 0; j < n; j++)
	{
		if (is_zero[j] == false)
		{
			is_posible = false;
			break;
		}
	}
	if (is_posible == true)
		cout << "yes";
	else
		cout << "no";
}