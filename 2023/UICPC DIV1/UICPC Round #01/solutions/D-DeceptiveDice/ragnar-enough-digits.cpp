#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
	int n, k; cin >> n >> k;

	double ev = (n+1)/2.;
	for(int i = 2; i <= k; ++i){
		// 1 ... floor(ev) k+1 ... n
		// ev       ev     k+1     n
		int k = floor(ev);
		ev = (k * ev + (n-k)*(n+k+1)/2)/n;
	}
	cout << setprecision(8) << ev << endl;
}
