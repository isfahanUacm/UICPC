#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int test_num;
	cin >> test_num;
	int n, m;
	for (int i = 0; i < test_num; i++)
	{
		cin >> n >> m;
		long long count = n - m + 1;
		//cout << fact(n) / (fact(m) * fact(n - m)) * m / count << endl;
		long long res = 1;
		if (n - m >= m)
		{
			bool* arr_m = new bool[m + 1];
			for (int k = 0; k < m + 1; k++)
				arr_m[k] = false;
			for (int k = n; k > n - m; k--)
			{
				res *= k;
				for (int jj = m; jj > 0; jj--)
				{
					if (res % jj == 0 && arr_m[jj] == false)
					{
						res /= jj;
						arr_m[jj] = true;
					}
				}
			}
		}
		else
		{
			bool* arr_n_m = new bool[n - m + 1];
			for (int k = 0; k < n - m + 1; k++)
				arr_n_m[k] = false;
			for (int k = n; k > m; k--)
			{
				res *= k;
				for (int jj = n - m; jj > 0; jj--)
				{
					if (res % jj == 0 && arr_n_m[jj] == false)
					{
						res /= jj;
						arr_n_m[jj] = true;
					}
				}
			}
		}
		cout << res * m / count << endl;
	}
}