#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

typedef long long ll;

int main() {
    srand(time(NULL));
    ll N = rand()%7+2;
    ll d = rand()%25+5;
    ll s = rand()%40+10;
    ll t = rand()%4;
    ll fmin = rand()%2000;
    ll fmax = rand()%2000;
    if (fmin > fmax) swap(fmin, fmax);

    cout << N << " " << d << " " << s << " " << t << " " << fmin << " " << fmax << endl;
    for (ll i = 0; i < 100; ++i) {
        cout << rand()%1800+200 << endl;
    }
}
