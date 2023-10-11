#include <iostream> // strings/streams
#include <vector> 
#include <random>
#include <ctime>


using namespace std;
using ll = long long;


int main()
{
	int n;
	cin >> n;
	vector<ll> sticks(n, 0);
	for(int i = 0; i < n; i++)
		cin >> sticks[i];
	
	bool possible = false;
	
        srand(time(NULL));
	for(int i = 0; i < 1000000; i++)
	{
		int a = rand() % n;
		int b = rand() % (n-1); 
		if(b >= a) b++;
		int c = rand() % (n-2);
		if(c >= min(a, b)) c++; if(c >= max(a, b)) c++;
		
		ll d = max(sticks[a], max(sticks[b], sticks[c]));
		if(sticks[a] + sticks[b] + sticks[c] > 2 * d)
			possible = true;		
	}
	
	if(possible)
			cout << "possible\n";
		else cout << "impossible\n";
	return 0;
}




