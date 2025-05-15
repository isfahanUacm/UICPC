#include <bits/stdc++.h>
using namespace std ;


int main() {
    int t=1 ;
    cin >> t ;
    while(t--)
    {
        int n, a;   cin >> n >> a;
        for(int i=0; i<n; i++)
            if(i!=a)
                cout << i << " ";
        if(a < n)
            cout << a << '\n';
        else
            cout << '\n';
    }
    return 0;
}
