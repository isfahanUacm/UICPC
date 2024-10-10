#include <iostream>
#include <math.h>
using namespace std;
int arr[110];
int cal(int i, int j) {
	int res = (i ^ j);
	int result=0;
	while (res) {
		result += (res % 2);
		res /= 2;

	}

	return result;
}
void solve() {
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	int _max = -1;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			_max = max(cal(arr[i], arr[j]), _max);
		}
	}
	cout << _max << endl;

		
}
int main() {
	cout << cal(12, 5);
	int t;
	cin >> t;

	while (t--) {
		solve();

	}
}
