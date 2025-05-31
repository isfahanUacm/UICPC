#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll fy = (a + b) / 2;
        ll sy = (a - b) / 2;
        cout << fy << " " << sy << "\n";
    }
    return 0;
}
