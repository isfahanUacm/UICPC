#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long double nn, pa;
long double k;
string letter = "AAAAAAAAAAAAAAA";
bool calc(int n, int i) 
{
	if (n == 0) {
		long double a = 0, b = 1;
		long double c;
		for (int j = 0; j < nn; j++) {
			 c = a + pa * (b - a);
			if (letter[j] == 'A') {
				b = c;
			}
			else a = c;
		}
		long double kk = k;
		
		while (kk > 1) kk /= 10;
		
		if (fabs((a - kk)) < 0.01)
		{
			for (int j = 0; j < nn; j++) cout << letter[j];
			return true;
		}
		return false;	
				

	}
	letter[i] = 'A';
	if (calc(n-1, i+1))
		return true;
	letter[i] = 'B';
	if (calc(n-1, i+1))
		return true;
	return false;
}

string num = "0123456789ABCDE";
int mtoten(string n, int m) {
	int multi = 1;
	int result = 0;
	for(int i = n.size()-1; i >= 0; i--) {
		result += num.find(n[i])*multi;
		multi *= m;
	}
	return result;
}

int main() {
	cin >> nn >> pa;
	pa = pa / 8;
	char c;
	cin >> c >> c;
	string str;
	cin >> str;
	k = mtoten(str, 2);

	calc(nn,0);

	return 0;
}
