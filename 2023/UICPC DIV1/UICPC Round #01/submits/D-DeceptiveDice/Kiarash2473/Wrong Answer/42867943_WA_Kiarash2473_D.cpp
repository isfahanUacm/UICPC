#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double n, k;
	cin >> n >> k;
	double avg = (n + 1) / 2;

	double behtar = 0;
	for (int i = n; i >= avg; i--)
	{
		behtar += i / n;
	}

	//cout << behtar << "hhhhhhh";
	double out = 0;
	for (int i = 1; i < k; i++)
	{
		out += (behtar / (pow(n / ((int)(n / 2)), i - 1)));
	}
	out += (avg / (pow(n / ((int)(n / 2)), k - 1)));

	cout.precision(10);
	cout << fixed << out;

}