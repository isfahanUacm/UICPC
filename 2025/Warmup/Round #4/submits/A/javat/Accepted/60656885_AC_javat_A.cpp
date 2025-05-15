using namespace std;
#include <iostream>
#include <vector>

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int len;
		int ones = 0;
		cin >> len;
		for (
			int j = 0; j < len;j++
			) {
			char c;
			cin >> c;
			if (c == '1') {
				ones++;
			}

		}
		int out = ones * (len - 1) + (len - ones);
		cout << out << endl;
	}
}

