#include <bits/stdc++.h>
using namespace std;

// Room Painting

#define num long long int

int n, m;
num a[100003], x, ans;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    ans = 0;
    while(m--){
        cin >> x;
        ans += *lower_bound(a, a+n, x) - x;
    }
    cout << ans << endl;
}