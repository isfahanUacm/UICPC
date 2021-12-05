#include <bits/stdc++.h>
using namespace std;

// Johnny Applesack

int main(){
    int n, k, ans = 0;
    cin >> n >> k;
    while(1){
        if(n <= k){
            ans += n;
            break;
        }
        n -= n / k + (n % k ? 1 : 0);
        ans++;
    }
    cout << ans + 1 << endl;
}