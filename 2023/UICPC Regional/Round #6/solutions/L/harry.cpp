#include <iostream> // strings/streams
#include <cstdio> // utils
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;
using ll  = long long;

// O(n^2 + k) solution.

int main()
{
	int n;
	cin >> n;
	assert(n >= 3); 
	assert(n <= 20000);
	vector<ll> sticks(n, 0);
	for(int i = 0; i < n; i++)
	{
		cin >> sticks[i];
		assert(n > 0);
		assert(n < llround(pow(2, 60)));
	}

	sort(sticks.begin(), sticks.end());
	
	bool possible = false;
	
	for(int i = 0; i < n-2; i++)
		if(sticks[i] + sticks[i+1] > sticks[i+2])
			possible = true;
			
	if(possible)
		cout << "possible\n";
	else cout << "impossible\n";
	
	return 0;
}




