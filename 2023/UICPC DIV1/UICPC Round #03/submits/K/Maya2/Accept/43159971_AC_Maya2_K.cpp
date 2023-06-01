#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e4 + 10;
string arr[maxn];

int main()
{
	int n;
	cin >> n;
	long double vak = 0, nvak = 0,bv = 0, bn = 0, av = 0, an= 0, cv = 0, cn = 0 ;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s[0] == 'Y') {
		       	vak++;
		if (s[1] == 'Y') av++;
		if (s[2] == 'Y') bv++;
		if (s[3] == 'Y') cv++;
		}
		
		else{
			if (s[1] == 'Y') an++;
			if (s[2] == 'Y' )bn++;
			if (s[3] == 'Y')cn++;
		       	nvak++;
		}
	}





	cout << fixed << setprecision(6);
	long double x = 1.0 * av / vak;
	long double y = 1.0 * an / nvak;

	if (x < y ) cout << ((y-x) / y) * 100;
	else cout << "Not Effective";
	cout << '\n';





	 x = 1.0 * bv / vak;
	 y = 1.0 * bn / nvak;

	if (x < y) cout << ((y-x) / y) * 100;
	else cout << "Not Effective";

	cout << '\n';





	 x = 1.0 * cv / vak;
	 y = 1.0 * cn / nvak;

	if (x < y) cout << ((y-x) / y) * 100;
	else cout << "Not Effective";

	return 0;
}

