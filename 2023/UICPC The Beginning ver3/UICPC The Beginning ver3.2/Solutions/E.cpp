#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	int n, m;
	cin >> n >> m;

	string k, b;
	cin >> k >> b;

	vector<char> a;
	for (int i = 0; i < m; i++) a.push_back(' ');

	for (int i = m - n; i < m; i++) a[i] = k[i - m + n];

	for (int i = m - n - 1; i >= 0; i--)
	{
		int t = b[i+n] - a[n + i];

		if (t < 0) t += 26;
		a[i] = (t % 26) + 97;
	}

	for (int i = 0; i < m; i++)
	{
		cout << a[i];
	}

}