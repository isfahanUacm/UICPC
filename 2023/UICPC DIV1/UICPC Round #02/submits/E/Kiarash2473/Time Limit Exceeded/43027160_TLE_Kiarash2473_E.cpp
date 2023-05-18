#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string arr;
	int res;
	for (int m = 0; m < n; m++)
	{
		res = 0;
		cin >> arr;
		int s_size = arr.size();
		for (int i = 1; i < s_size; i++)
		{
			for (int k = 0; k < s_size - i; k++)
			{
				bool in_ghabl = true;
				if (arr.find(arr.substr(k, i), 0) == k)
					in_ghabl = false;
				if (arr.find(arr.substr(k, i), k + 1) != string::npos && in_ghabl == false)
					res++;
			}
		}
		cout << res << endl;
	}
}