#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	long long int max = 0;
	long long int tmp0 = 0;
	long long int tmp1 = sum;
	for (int k = 0; k < n; k++)
	{
		tmp0 += arr[k] * arr[k];
		tmp1 -= arr[k];
		if (tmp0 * tmp1 > max)
		{
			max = tmp0 * tmp1;
		}
	}

	cout << max;
}