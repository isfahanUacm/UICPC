//Author: Fredrik Svensson
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int ret = 0;
	string line;
	getline(cin, line);
	for (int i = 0; i < n; ++i)
	{
		getline(cin, line);
		if (line.find("CD") == string::npos)
			++ret;
	}
	cout << ret << endl;
	return 0;
}
