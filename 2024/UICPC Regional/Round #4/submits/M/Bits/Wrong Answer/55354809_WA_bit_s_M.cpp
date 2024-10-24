#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;
    if(n==1||n==3||n==4||n==5||n==6)
    {
        cout<<"20 30 40\n";
    }else if(n==2)
    {
        cout<<"3 4 7\n";
    }else
    {
        cout<<"1 2 3\n";
    }
}


int main()
{
    solve();

    return 0;
}
