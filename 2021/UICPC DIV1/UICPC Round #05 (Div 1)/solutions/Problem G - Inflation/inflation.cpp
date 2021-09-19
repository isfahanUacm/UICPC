#include <bits/stdc++.h>
using namespace std;

// Inflation

int n, a[200003];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    double ans = 1;
    for(int i = 0; i < n; i++){
        if(a[i] > i + 1){
            cout << "impossible" << endl;
            return 0;
        }
        ans = min(ans, double(a[i]) / (i + 1));
    }
    cout << fixed << setprecision(10) << ans << endl;
}