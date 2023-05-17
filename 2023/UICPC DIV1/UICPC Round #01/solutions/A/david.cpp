#include <iostream>

using namespace std;

int main() {
	int R, C;
	cin >> R >> C;

	int Rmax = 0;
	for (int i=0; i<R; i++) {
		int cur;
		cin >> cur;
		if (cur > Rmax) Rmax = cur;
	}

	int Cmax = 0;
	for (int i=0; i<C; i++) {
		int cur;
		cin >> cur;
		if (cur > Cmax) Cmax = cur;
	}

	if (Rmax == Cmax)
		cout << "possible" << endl;
	else
		cout << "impossible" << endl;

	return 0;
}
