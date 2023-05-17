#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int n, k; cin >> n >> k;

	double ev = (n+1)/2.;
	for(int i = 2; i <= k; ++i){
		double new_ev = 0;
		for(int v = 1; v <= n; ++v)
			new_ev += max(double(v), ev);
		new_ev /= n;
		ev = new_ev;
	}
	cout << setprecision(12) << fixed << ev << endl;
}
