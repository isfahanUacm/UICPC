#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	string* name = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i] >> name[i];
	}

	for (int p = 0; p < n; p++)
	{
		bool is_tie = false;
		int div_count = 0;
		int prime_pow[2];
		for (int i = 2; i <= sqrt(arr[p]); i++)
		{
			bool is_prime = true;
			for (int j = 2; j <= sqrt(i); j++)
			{
				if (i % j == 0)
				{
					is_prime = false;
					break;
				}
			}
			if (is_prime == true && arr[p] % i == 0)
			{
				div_count++;
				if (div_count > 2)
				{
					is_tie = true;
					break;
				}
				int tavan = 0;
				double temp = arr[p];
				while (ceil(temp / i) == floor(temp / i))
				{
					tavan++;
					temp /= i;
				}
				prime_pow[div_count - 1] = tavan;
				arr[p] = arr[p] / (pow(i, tavan));
			}
		}

		if (is_tie == true)
			cout << "tie" << endl;
		else if (arr[p] != 1 && div_count == 2)
			cout << "tie" << endl;
		else if (arr[p] != 1 && div_count == 1 && prime_pow[0] > 2)
			cout << "tie" << endl;
		else if (arr[p] != 1 && div_count == 0)
			cout << name[p] << endl;
		else if (arr[p] != 1 && div_count == 1 && prime_pow[0] == 2)
			cout << name[p] << endl;
		else if (arr[p] != 1 && div_count == 1 && prime_pow[0] == 1)
			if (name[p] == "Bob")
				cout << "Alice" << endl;
			else
				cout << "Bob" << endl;
		else if (arr[p] == 1 && div_count == 1 && prime_pow[0] % 2 == 0)
			if (name[p] == "Bob")
				cout << "Alice" << endl;
			else
				cout << "Bob" << endl;
		else if (arr[p] == 1 && div_count == 1 && prime_pow[0] % 2 == 1)
			cout << name[p] << endl;
		else if (arr[p] == 1 && div_count == 2 && abs(prime_pow[1] - prime_pow[0]) > 1)
			cout << "tie" << endl;
		else if (arr[p] == 1 && div_count == 2 && abs(prime_pow[1] - prime_pow[0]) == 1)
			cout << name[p] << endl;
		else if (arr[p] == 1 && div_count == 2 && abs(prime_pow[1] - prime_pow[0]) == 0)
			if (name[p] == "Bob")
				cout << "Alice" << endl;
			else
				cout << "Bob" << endl;
	}
}