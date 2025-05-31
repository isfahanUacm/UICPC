#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        ll L, R;
        cin >> L >> R;
        ll up = floor(sqrt((ld)R));
        ll low = 0;
        if(L > 1)
            low = floor(sqrt((ld)(L - 1)));
        else
            low = 0;
        cout << (up - low) << "\n";
    }
    return 0;
}
