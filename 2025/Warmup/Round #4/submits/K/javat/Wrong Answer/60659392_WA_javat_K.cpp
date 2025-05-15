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
		//cout << days << " ";

	}
	//for (int i = 0;i < n;i++) {
	//	cout << rest[i] << " ";
	//}
	//cout << endl;
	if (days % 2 != 0)

	{
		//days += n;
		max++;
	}
	//days /= 2;
	//days += d;
	cout << max;

}

