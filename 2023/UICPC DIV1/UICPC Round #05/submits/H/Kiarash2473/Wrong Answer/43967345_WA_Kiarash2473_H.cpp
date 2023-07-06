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
		double pc = ceil(p[i]);

		if (b[i] >= pc)
		{
			long double ratio = 1 + 2 * (b[i] / pc - 1);
			long double min_ABPM = bpm / b[i] * pc;
			long double max_ABPM = min_ABPM * ratio;
			cout << min_ABPM << " " << bpm << " " << max_ABPM << endl;
		}
		else
		{
			long double ratio = 1 + 2 * (pc / b[i] - 1);
			long double min_ABPM = bpm * b[i] / pc;
			long double max_ABPM = min_ABPM * ratio;
			cout << min_ABPM << " " << bpm << " " << max_ABPM << endl;
		}
	}
}