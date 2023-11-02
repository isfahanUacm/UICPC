#include <iostream>
#include <random>

using namespace std;

typedef long long ll;

ll rand_int(ll low, ll high) {
    return rand()%(high-low+1)+low;
}

int main() {
    default_random_engine gen;
    uniform_real_distribution<double> dist(.009,1.0);
    for (ll i = 0; i < 100; ++i) {
        cout << rand_int(100, 5280) << " " << dist(gen) << endl;
    }
}
