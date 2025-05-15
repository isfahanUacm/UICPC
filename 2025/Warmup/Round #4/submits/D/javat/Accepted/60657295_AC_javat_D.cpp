using namespace std;
#include <iostream>


int main()
{
	long long n = 0;
	cin >> n;
	long long a, b;
	cin >> a >> b;
	long long c, d;
	cin >> c >> d;
	long long out = ((c - a) * (n + 1)) + (d - b);
	cout << out;

}