using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>


int main()
{
	int n, d;
	cin >> n >> d;
	vector<int> rest(n);
	for (int i = 0;i < n;i++) {
		rest[i] = 0;
	}
	for (int i = 0;i < d;i++) {
		int a, b;
		cin >> a >> b;
		rest[a - 1]++;
		rest[b - 1]++;
	}
	int max = *max_element(rest.begin(), rest.end());
	int days = 0;
	for (int i = 0;i < n;i++) {
		days += max - rest[i];


	}
	if (max == days) {
		if (n % 2 != 0) {
			max *= 2;
		}
	}
	else if (days % 2 != 0)

	{

		max++;
	}

	cout << max;

}

