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
    int n ;
    cin >> n;
    long double arr[n];
    long double arr2[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0 ; i <n ; i++) {
        cin>>arr2[i];
    }
    for (int i = 1 ; i < n ; i++) {
        arr2[i] = arr2[i]+arr2[i-1];
    }
    long double m = 0;
    long double c =0;
    for (int i = 0; i < n; i++) {
        long double fe = ((arr2[i]+arr[i])/(c+1));
        if (fe > m) {
            m = fe;
            c= i+1;
        }
    }
    cout << fixed << setprecision(1)<<m << endl;
    return 0;
}
