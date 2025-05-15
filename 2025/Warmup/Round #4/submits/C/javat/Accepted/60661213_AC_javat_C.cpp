using namespace std;
#include <iostream>
#include <string>

int main()
{
	long long n = 0;
	cin >> n;
	for (int i = 0;i < n;i++) {
		string num = "\0";
		cin >> num;
		int count = 0;
		while (num[num.length() - 1] == '0') {
			num = num.substr(0, num.length() - 1);
			count++;
		}
		while (num.length() != 0) {
			if (num[num.length() - 1] != '0') {
				count++;
			}
			num = num.substr(0, num.length() - 1);
		}
		count--;
		cout << count << endl;
	}
}