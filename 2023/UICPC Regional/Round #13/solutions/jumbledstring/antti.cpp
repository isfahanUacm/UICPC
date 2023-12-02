#include <iostream>
#include <cstdio>

using namespace std;

int c00, c01, c10, c11;
int c0, c1;
string s;

void fail() {
	cout << "impossible\n";
	exit(0);
}

void brute(string u, int u0, int u1, int u00, int u01, int u10, int u11) {
	if (u.size() && u00 == c00 && u01 == c01 && u10 == c10 && u11 == c11) {
		cout << u << "\n";
		exit(0);
	}
	if (u.size() == 10) return;
	brute(u+"0",u0+1,u1,u00+u0,u01,u10+u1,u11);
	brute(u+"1",u0,u1+1,u00,u01+u0,u10,u11+u1);
}

int main() {
	cin >> c00 >> c01 >> c10 >> c11;

	// handle small special cases
	brute("",0,0,0,0,0,0);

	// general case
	while (c0*(c0-1)/2 < c00) c0++;
	if (c0*(c0-1)/2 > c00) fail();
	while (c1*(c1-1)/2 < c11) c1++;
	if (c1*(c1-1)/2 > c11) fail();
	while (c0 || c1) {
		if (c01 >= c1) {
			c01 -= c1;
			c0--;
			s += "0";
		} else {
			c10 -= c0;
			c1--;
			s += "1";
		}
	}
	if (c01 || c10) fail();
	cout << s << "\n";
}
