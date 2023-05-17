#include <iostream>
#include <vector>

using namespace std;

vector<int> factor(int n) {
	vector<int> f;
	int k = 2;
	while( n > 1 and k*k <= n ) {
		while( n % k == 0 ) {
			f.push_back(k);
			n /= k;
		} 
		k++;
	}

	if( n > 1 )
		f.push_back(n);

	return f;
}

int main() {


	int n;
	cin >> n;

	vector<int> f = factor(n);
	int F = f.size();

	// n <= 10^6, so F < 20;
	for( int k = 0; k < (1<<F); k++ ) {
		int x = 1;
		for( int i = 0; i < F; i++ ) {
			if( k&(1<<i) )
				x *= f[i];
		}

		int y = n/x;

		if( x*y == n and (x+y)%2 == 0 ) {
			std::cout << (x+y)/2 << " " << (y-x)/2 << std::endl;
			return 0;
		}
	}

	std::cout << "impossible" << std::endl;

	return 0;
}