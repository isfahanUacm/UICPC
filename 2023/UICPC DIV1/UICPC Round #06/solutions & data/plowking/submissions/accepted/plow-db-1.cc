// Problem    : Mr. Plow King
// Author     : Darcy Best
// Complexity : O(1)

// Computes the answer modulo 2^64. However, the answer is guaranteed to be < 10^18,
// so we know the answer!

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull triangle(ull x){
    if(x % 2 == 0) return (x/2) * (x+1);
    return x * ( (x+1)/2 );
}

int main(){
	ull n, m;
	cin >> n >> m;
    
    // d*(d-1)/2 + (n-d) >= m
    // 1/2 * d^2 - 1/2 * d + n - d >= m
    // 1/2 * d^2 - 3/2 * d + (n-m) >= 0
    // d^2 - 3*d + 2*(n-m) >= 0
    
	ull d = (3 + sqrt(3*3 - 4*2*(n-m))) / 2;
	// d == 1 is a solution if we have a tree...
	if(1 - 3 + 2*(n-m) >= 0) d = 1;
	
	while(d * (d-1) / 2 + (n - d) < m) d++;
    
    // sum of (i * (i-1) / 2 + 1) for i from 1 to d-1
    ull ans = (d*d*d - 3*d*d + 8*d - 6) / 6;

    // Note there is overflow here... But managable...
    ans += triangle(m);
    ans -= triangle(m-n+d);

	cout << ans << endl;
	
}
