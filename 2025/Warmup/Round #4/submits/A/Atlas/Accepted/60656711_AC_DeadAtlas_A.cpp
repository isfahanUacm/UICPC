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
        int ans = 0;
        int n;
        cin >> n;
        string s;
        cin >> s;
        for(int i = 0; i < n; i++) {
            if (s[i] == '1') ans += (n-1);
            else ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
