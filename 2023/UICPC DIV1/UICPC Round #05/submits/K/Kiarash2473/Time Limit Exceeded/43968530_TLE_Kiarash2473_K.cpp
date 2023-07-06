#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> task;
	vector<int> quiet;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		task.push_back(tmp);
	}
	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		quiet.push_back(tmp);
	}

	sort(task.begin(), task.end(), greater<int>());
	sort(quiet.begin(), quiet.end(), greater<int>());

	int res = 0;
	for (int i = 0; i < task.size(); i++)
	{
		for (int j = 0; j < quiet.size(); j++)
		{
			if (task[i] <= quiet[j])
			{
				res++;
				vector<int>::iterator it;
				it = quiet.begin() + j;
				quiet.erase(it);
				break;
			}
		}
	}

	cout << res;
}