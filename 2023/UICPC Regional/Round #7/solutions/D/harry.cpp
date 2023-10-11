#include <iostream> // strings/streams
#include <cstdio> // utils
#include <string>
#include <cstring>
#include <sstream>
#include <vector> // datastructures
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <tuple> // quick compare
#include <numeric>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <cassert>
#include <complex>

#define REP(i,n)	for(auto i = decltype(n)(0); i<(n); i++)
#define all(v)		begin(v), end(v)

using namespace std;
using ll  = long long;
using ull = unsigned long long;
using ld  = long double;
using ii  = pair<ll,ll>;
using vi  = vector<ll>;
using vii = vector<ii>;
using vb  = vector<bool>;
using vvi = vector<vi>;
using vvii = vector<vii>;

constexpr int  INF = 1e9+1; // < 1e9 - -1e9
constexpr ll LLINF = 1e18+1;




int main()
{
	int n;
	cin >> n;
	vector<int> boats(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> boats[i];
	}
	vector<vector<int>> times(n, vector<int>(n));
	
	for(int i = 0; i < n; ++i)
		for(int j = i; j < n; ++j)
		{
			times[i][j] = 120 + max(20*(j - i + 1), (boats[j] + 20) - (boats[i] + 1800)); 
			// To let boats i..j (inclusive) pass, we need 120 minutes for opening and closing the bridge, at least 20 minutes per boat. We can let the boats wait at most 1800 minutes.
			// Because the boats are at least twenty minutes apart, the second part of min is correct.
		}
		
	vector<int> dp(n); // dp[i] stores the shortest time needed to let boats 0..i (inclusive) pass. 	
	
	for(int i = 0; i < n; ++i)
	{
		int low = times[0][i]; // We let the boats all pass at once.
		for(int k = 1; k <= i; ++k) // If we don't let all boats pass, then there is a boat 0 < k <= i  such that we let boats k..i all pass at once.
		{
			low = min(low, times[k][i] + dp[k - 1]);
		}
		dp[i] = low; // We have considered all options and take the lowest one. 
	}
	// Note that for dp[i] we only need dp[j] with j < i, so we can pass through this dp linearly, so that we don't need any recursive functions.
	
	cout << dp[n-1] << "\n";
	
	
	return 0;
}




