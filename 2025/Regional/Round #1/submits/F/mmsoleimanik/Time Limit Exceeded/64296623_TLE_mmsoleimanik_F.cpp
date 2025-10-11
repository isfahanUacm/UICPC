#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef int long long ll;

ll minCykleNumber(ll number) {
    ll maxInCykle = 1 , counter = 0 , minNumber = 0;

    ll m= 1 , step = 1;

    while (minNumber < number) {

        for (int i=0; i<maxInCykle*2-1; i++) {
            minNumber += step;

            if (step == maxInCykle) {
                m = -1;
            }

            counter ++;
            if (minNumber >= number) break;
            step += m;
        }

        m=1;
        maxInCykle++;
        step=1;
    }

    return counter;
}

int main() {
    freopen("army.in" , "r" , stdin);
    int t;
    cin >> t;

    ll ans[100000];
    for (int i=0; i<t; i++) {
        ll number;
        cin >> number;
        ans[i] = minCykleNumber(number);
    }

    for (int i=0; i<t; i++) {
        cout << "Case " << i+1 << ": " << ans[i] << endl;
    }
    return 0;
}