#include <algorithm>
#include <iostream>
#include <math.h>
#include <bits/ranges_algo.h>

using namespace std;

typedef long long ll;

int main() {


    int t;
    cin >> t;


    while (t--) {
        int n;
        cin >> n;
        int x;
        cin >> x;
        for (int i = 0; i < n; i++) {
            if (i < x) cout << i << " ";
            else if (i > x) cout << i << " ";
        }
        if (x >= n) cout << endl;
        else cout << x << endl;
    }

    // int n;
    // cin >> n;



    return 0;
}
