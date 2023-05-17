#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	bool is_find = false;

	for (int i = 1; n / i >= i; i++)
	{
		if (n % i == 0)
		{
			int sum = n / i;
			if ((sum + i) % 2 == 0)
			{
				is_find = true;
				cout << (sum + i) / 2 << " " << (sum - i) / 2;
				break;
			}
		}
	}
	if (is_find == false)
		cout << "impossible";

}