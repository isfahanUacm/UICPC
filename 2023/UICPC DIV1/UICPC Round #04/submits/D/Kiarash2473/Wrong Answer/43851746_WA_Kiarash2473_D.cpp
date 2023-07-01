#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

bool sortbysec(const pair<int, int>& a, const pair<int, int>& b)
{
	return (a.second < b.second);
}

double dist(const pair<int, int>& a, const pair<int, int>& b)
{
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> cor;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		cor.push_back(make_pair(x, y));
	}

	sort(cor.begin(), cor.end(), sortbysec);

	vector<pair<int, int>> min_y;
	min_y.push_back(make_pair(cor[0].first, cor[0].second));
	for (int i = 1; i < cor.size(); i++)
	{
		if (cor[i].second == min_y[0].second)
		{
			min_y.push_back(make_pair(cor[i].first, cor[i].second));
		}
		else
			break;
	}

	sort(min_y.begin(), min_y.end());
	vector<pair<int, int>> result;
	result.push_back(min_y[0]);
	result.push_back(min_y[min_y.size() - 1]);

	////////////////////////////////////////////////////////////////

	vector<pair<int, int>> max_y;
	max_y.push_back(make_pair(cor[cor.size() - 1].first, cor[cor.size() - 1].second));
	for (int i = cor.size() - 2; i >= 0; i--)
	{
		if (cor[i].second == max_y[0].second)
		{
			max_y.push_back(make_pair(cor[i].first, cor[i].second));
		}
		else
			break;
	}

	sort(max_y.begin(), max_y.end());
	result.push_back(max_y[0]);
	result.push_back(max_y[max_y.size() - 1]);

	////////////////////////////////////////////////////////////////

	sort(cor.begin(), cor.end());

	vector<pair<int, int>> min_x;
	min_x.push_back(make_pair(cor[0].first, cor[0].second));
	for (int i = 1; i < cor.size(); i++)
	{
		if (cor[i].first == min_x[0].first)
		{
			min_x.push_back(make_pair(cor[i].first, cor[i].second));
		}
		else
			break;
	}

	sort(min_x.begin(), min_x.end());
	result.push_back(min_x[0]);
	result.push_back(min_x[min_x.size() - 1]);

	////////////////////////////////////////////////////////////////

	vector<pair<int, int>> max_x;
	max_x.push_back(make_pair(cor[cor.size() - 1].first, cor[cor.size() - 1].second));
	for (int i = cor.size() - 2; i >= 0; i--)
	{
		if (cor[i].first == max_y[0].first)
		{
			max_x.push_back(make_pair(cor[i].first, cor[i].second));
		}
		else
			break;
	}

	sort(max_x.begin(), max_x.end());
	result.push_back(max_x[0]);
	result.push_back(max_x[max_x.size() - 1]);

	////////////////////////////////////////////////////////////////

	double max_dist = 0;
	for (int i = 0; i < result.size(); i++)
	{
		for (int p = 0; p < result.size(); p++)
		{
			double curr = dist(result[i], result[p]);
			if (curr > max_dist)
				max_dist = curr;
		}
	}

	cout << fixed << setprecision(8) << max_dist;
}