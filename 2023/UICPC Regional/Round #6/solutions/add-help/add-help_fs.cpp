#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		if(str == "P=NP")
			cout << "skipped" << endl;
		else
		{
			istringstream iss(str);
			int a, b;
			iss >> a >> b;
			cout << a+b << endl;
		}
	}
	return 0;
}
