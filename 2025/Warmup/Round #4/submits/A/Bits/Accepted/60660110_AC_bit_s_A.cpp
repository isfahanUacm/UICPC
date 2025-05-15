#include <bits/stdc++.h>
using namespace std ;
int main() {
    int t ; cin >> t ;
    while(t--)
    {
        int n; cin >> n ;
        string s ; cin >> s;
        int cnt = 0;
        for(int i =0  ;i < n ; i ++)
        {
            if(s[i] == '1')
                cnt ++;
        }
        cout << cnt*n - cnt + n-cnt << '\n';
    }
    return 0;
}
