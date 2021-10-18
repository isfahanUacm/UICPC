#include <bits/stdc++.h>
using namespace std;

// Coloring Socks

int s, c, k, a[100003];

int main(){
    cin >> s >> c >> k;
    for(int i = 0; i < s; i++)
        cin >> a[i];
    sort(a, a + s);
    int ans = 1, cap = 1, dre = a[0];
    for(int i = 1; i < s; i++){
        if(cap == c || a[i] - dre > k)
            ans++, cap = 1, dre = a[i];
        else
            cap++;
    }
    cout << ans << endl;
}