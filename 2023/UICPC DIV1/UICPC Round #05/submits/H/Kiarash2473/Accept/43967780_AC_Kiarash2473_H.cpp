#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* b = new int[n];
	double* p = new double[n];
	for (int i = 0; i < n; i++)
	{
		cin >> b[i] >> p[i];
	}

	cout.precision(8);
	for (int i = 0; i < n; i++)
	{
		long double bpm = 60 * b[i] / p[i];
		long double min_abpm = 60 * (b[i] - 1) / p[i];
		long double max_abpm = 60 * (b[i] + 1) / p[i];
		cout << min_abpm << " " << bpm << " " << max_abpm << endl;
	}
}