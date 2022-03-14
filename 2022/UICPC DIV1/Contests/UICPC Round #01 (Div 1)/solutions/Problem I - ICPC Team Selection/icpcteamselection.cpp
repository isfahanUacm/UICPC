#include <bits/stdc++.h>
using namespace std;

// ICPC Team Selection

int t, n;
int a[303];

int main(){
    cin >> t;
    while(t--){
        cin >> n, n *= 3;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a+n);
        int ans = 0;
        int i = 0, j = n - 1;
        while(i < j)
            ans += a[j-1], i++, j-= 2;
        cout << ans << endl;
    }
}