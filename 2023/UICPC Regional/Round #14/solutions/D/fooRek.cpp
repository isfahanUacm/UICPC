// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <list>
#include <cmath>
using namespace std;

bool mark[1000];
int c[1000][2];
int tclen;

void rek(int n) {
	if(mark[n]) return;
	mark[n] = true;
	for(int i = 0; i < tclen; i++) {
		if(    abs(c[n][0] - c[i][0]) 
		     + abs(c[n][1] - c[i][1]) <= 1000) {
			rek(i);
		}
	}
}

int main() {
	int ntc;
	cin >> ntc;
	while (ntc--) {
		cin >> tclen;
		tclen += 2;
		for(int i = 0; i < tclen; i++) {
			cin >> c[i][0];
			cin >> c[i][1];
			mark[i] = false;
		}
		rek(0);
		cout << (mark[tclen-1] ? "happy" : "sad") << endl;
	}
	
	return 0;
}
