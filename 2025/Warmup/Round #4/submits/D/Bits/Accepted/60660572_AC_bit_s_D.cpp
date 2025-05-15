#include <bits/stdc++.h>
using namespace std ;


int main() {
    int t=1 ;
//    cin >> t ;
    while(t--)
    {
        int n; cin >> n;
        int a,b; cin >> a >> b;
        int c,d; cin >> c >> d;

        if(a == c)
        {
            cout << d - b;
            return 0;
        }

        int otp = n+1;
        otp *= (c-a-1);
        otp += n-b;
        otp += d+1;

        cout << otp;
    }
    return 0;
}
