#include <iostream>
#include <cassert>
using namespace std;
int main(){
	// c++14 test
	auto lambda = [](auto x, auto y) {return x + y;};

	long long n;
	cin >> n;

	if(n%2 == 1){
		// (k+1)^2 - k^2 = 2k+1 = n
		cout << (n+1)/2 << ' ' << n/2 << endl;
		return 0;
	}

	if(n%4 == 2){
		cout << "impossible" << endl;
		return 0;
	}

	assert(n%4==0);
	
	// (k+2)^2 - k^2 = 4k+4 = n
	cout << n/4+1 << ' ' << n/4-1 << endl;
}
