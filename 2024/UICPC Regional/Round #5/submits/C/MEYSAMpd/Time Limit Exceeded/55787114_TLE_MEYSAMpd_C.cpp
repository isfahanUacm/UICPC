#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long int
#define ll long long int

int main() {
    ull t; cin >> t;
    while (t--) {
        ull n, k;
        cin >> n >> k;
        vector<ull> nums;
        ull tmp;
        for (ull i=0 ; i<n; i++) {
            cin >> tmp;
            nums.push_back(tmp);
        }



        ll change;
        for (ull i=0 ; i<k; i++) {
            cin >> change;
            for (ll j=0; j<change/2; j++) {
                nums.erase(nums.begin() + j);
            }
            ll tmp2 = change/2;
            reverse(nums.begin(), nums.begin() + tmp2);

        }

        for (unsigned long long num : nums) {
            cout << num << " ";
        }
    }

    return 0;
}