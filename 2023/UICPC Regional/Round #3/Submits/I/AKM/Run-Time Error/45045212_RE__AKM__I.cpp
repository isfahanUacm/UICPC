#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string bapc;
		cin >> bapc;
		int n;
		cin >> n;
		deque<int> arr;
		string list;
		cin >> list;
		string tmp = "";
		for (int j = 1; j < list.size(); j++)
		{
			if (list[j] == ',')
			{
				arr.push_back(stoi(tmp));
				tmp.clear();
			}
			else if (list[j] != ']')
			{
				tmp.push_back(list[j]);
			}
			else if (tmp.size() > 0)
			{
				arr.push_back(stoi(tmp));
			}
		}
		if (count(bapc.begin(), bapc.end(), 'D') > n)
		{
			cout << "error" << endl;
		}
		else
		{
			int R_count = 0;
			string res;
			res.push_back('[');

			for (int j = 0; j < bapc.size(); j++)
			{
				if (bapc[j] == 'R')
					R_count++;
				else if (R_count % 2 == 0)
				{
					arr.pop_front();
				}
				else
				{
					arr.pop_back();
				}
			}
			if (R_count % 2 == 1)
			{
				reverse(arr.begin(), arr.end());
			}
			for (int j = 0; j < arr.size() - 1; j++)
			{
				res.append(to_string(arr[j]));
				res.push_back(',');
			}
			if (arr.size() - 1 >= 0)
				res.append(to_string(arr[arr.size() - 1]));

			res.push_back(']');
			cout << res << endl;
		}
	}
}