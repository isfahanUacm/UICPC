#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string before, after;
	cin >> before >> after;
	int min_size = before.size();
	int max_size = after.size();
	if (before.size() > after.size())
	{
		min_size = after.size();
		max_size = before.size();
	}

	int first_ind = -1;
	for (int i = 0; i < min_size; i++)
	{
		if (after[i] != before[i])
		{
			first_ind = i;
			break;
		}
	}
	if (first_ind == -1 && min_size == before.size())
	{
		cout << max_size - min_size;
		return 0;
	}
	if(first_ind == -1 && min_size == after.size())
	{
		cout << 0;
		return 0;
	}

	reverse(before.begin(), before.end());
	reverse(after.begin(), after.end());

	int second_ind = -1;
	for (int i = 0; i < min_size; i++)
	{
		if (after[i] != before[i])
		{
			second_ind = i;
			break;
		}
	}
	if (second_ind == -1 && min_size == before.size())
	{
		cout << max_size - min_size;
		return 0;
	}
	if (second_ind == -1 && min_size == after.size())
	{
		cout << 0;
		return 0;
	}

	//if (first_ind + second_ind + 2 == min_size && before.size() == min_size)
	//{
	//	cout << max_size - min_size;
	//	return 0;
	//}
	if (first_ind + second_ind + 2 == min_size && after.size() == min_size)
	{
		cout << 0;
		return 0;
	}

	cout << after.size() - first_ind - second_ind;
}