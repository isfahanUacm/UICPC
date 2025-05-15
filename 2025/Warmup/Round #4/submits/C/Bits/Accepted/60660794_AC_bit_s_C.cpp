#include <bits/stdc++.h>
using namespace std ;


int main() {
    int t=1 ;
    cin >> t ;
    while(t--)
    {
        string s; cin >> s;
        int count_z = 0;
        bool flag = false;
        for(auto x=s.rbegin(); x<s.rend(); x++)
        {
            if(*x != '0') flag = true;
            if(flag && *x=='0') count_z ++;
        }
        int si = s.size() ;
        cout << max(si - 1 - count_z , 0) << '\n';

    }
    return 0;
}
