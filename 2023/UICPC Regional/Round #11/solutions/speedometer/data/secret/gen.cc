#include <iostream>
#include <cstdlib>

using namespace std;

typedef long long ll;

int main() {
    cout << "0.15" << endl;
    cout << "0.25" << endl;
    for (ll i = 0; i < 1000; ++i) {
        cout << rand()%119 << "." << rand()%10 << endl;
    }
}
