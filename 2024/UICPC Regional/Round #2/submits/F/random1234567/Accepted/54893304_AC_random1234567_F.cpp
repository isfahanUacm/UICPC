#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << ((a == b) ? "Square" : "Rectangle");
		cout << endl;

	}
}
