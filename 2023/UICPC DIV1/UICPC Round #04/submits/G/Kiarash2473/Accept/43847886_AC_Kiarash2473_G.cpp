#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string one, two;
	cin >> one >> two;

	if (n % 2 == 0)
	{
		if (one == two)
			cout << "Deletion succeeded";
		else
			cout << "Deletion failed";
	}
	else
	{
		bool is_reverse = true;
		for (int i = 0; i < one.size(); i++)
		{
			if (one[i] == two[i])
			{
				is_reverse = false;
				break;
			}
		}
		if (is_reverse == true)
			cout << "Deletion succeeded";
		else
			cout << "Deletion failed";
	}
}