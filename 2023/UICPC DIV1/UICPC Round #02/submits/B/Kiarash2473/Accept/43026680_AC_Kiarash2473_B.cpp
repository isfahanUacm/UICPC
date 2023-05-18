#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string** arr = new string * [n];
	for (int i = 0; i < n; i++)
		arr[i] = new string[4];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++)
	{
		string year_2010 = arr[i][1].substr(0, 4);
		string year_1991 = arr[i][2].substr(0, 4);
		if (stoi(year_1991) >= 1991)
		{
			cout << arr[i][0] << " " << "eligible" << endl;
			continue;
		}
		if (stoi(year_2010) >= 2010)
		{
			cout << arr[i][0] << " " << "eligible" << endl;
			continue;
		}
		if (stoi(arr[i][3]) > 40)
		{
			cout << arr[i][0] << " " << "ineligible" << endl;
			continue;
		}
		else
		{
			cout << arr[i][0] << " " << "coach petitions" << endl;
			continue;
		}
	}
}