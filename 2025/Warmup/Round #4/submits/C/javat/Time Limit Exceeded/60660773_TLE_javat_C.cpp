using namespace std;
#include <iostream>
#include <vector>

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int num = 0;
		cin >> num;
		int count = 0;
		while (num % 10 == 0) {
			num /= 10;
			count++;
		}
		while (num != 0) {
			if (num % 10 != 0) {
				count++;
			}
			num /= 10;
		}
		count--;
		cout << count << endl;
	}
}

