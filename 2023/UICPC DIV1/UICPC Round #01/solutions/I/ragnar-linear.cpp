#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n; cin >> n;
	vector<long long> v(n);
	long long p = 0, s = 0;
	for(auto&x : v) cin >> x, s += x;
	long long ans = 0;
	for(auto x : v) p+=x*x, s-=x, ans = max(ans, p*s);
	cout << ans << endl;
}
