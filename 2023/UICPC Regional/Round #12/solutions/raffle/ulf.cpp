#include <iostream>
using namespace std;

int main() {
	int n, p;
	cin >> n >> p;
	int a = n/(p-1);
	double res = double(a*p) / (n-p+1);
	for (int i = 0; i < a; ++i) {
		res *= double(n-p+1+i) / (n+1+i);
	}
	cout << res << endl;
}