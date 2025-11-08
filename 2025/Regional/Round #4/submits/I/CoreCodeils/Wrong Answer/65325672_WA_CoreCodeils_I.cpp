#include <iomanip>
#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define endl "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ;
    cin >> n;
    ll arr[n];
    ll arr2[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0 ; i <n ; i++) {
        cin>>arr2[i];
    }
    for (int i = 1 ; i < n ; i++) {
        arr2[i] = arr2[i]+arr2[i-1];
    }
    ll m = 0;
    ll c =0;
    for (int i = 0; i < n; i++) {
        if (arr2[i]+arr[i] > m) {
            m = arr2[i]+arr[i];
            c= i+1;
        }
    }
    double res = (double)m/n;
    cout << fixed << setprecision(1)<<res << endl;


    return 0;
}
