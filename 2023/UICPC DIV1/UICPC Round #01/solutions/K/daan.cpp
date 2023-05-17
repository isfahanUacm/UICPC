#include <iostream>
#include <vector>
#include <algorithm>

#define INFTY (1<<30)

int main() {
	int n;
	std::cin >> n;
	std::vector<int> S((1<<n)+1), T((1<<n)+1), ans;
	for( int i = 0; i < (1<<n); ++i )
		std::cin >> S[i];
	std::sort( S.rbegin(), S.rend() );

	// --- Required if we allow input length 0
	// if( S.back() != 0 )
	// 	goto impossible;
	// ---

	for( int k = n; k > 0; --k ) {
		int b = 1<<k;
		S[b] = -INFTY;
		int x = S[b-2], u = 0, l = 1, t = 0;
		if( x == 0 ) { // edge case
			while( u < b ) {
				T[t++] = S[u];
				if( S[u] != S[u+1] ) 
					goto impossible;
				u += 2;
			}
		} else { // general case
			while( l < b ) {
				while( S[u] == -1 ) ++u;
				while( S[l]+x > S[u] ) ++l;
				if( S[l]+x < S[u] ) 
					goto impossible;
				T[t++] = S[l];
				S[l++] = -1;
				++u;
			}
		}
		ans.push_back(x);
		if( t != (b>>1) )
			goto impossible;
		swap(S,T);
	}
	for( int x : ans )
		std::cout << x << std::endl;
	return 0;
impossible:
	std::cout << "impossible" << std::endl;
}