#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n; cin >> n;
    if(n==2||n==4)
    {
        cout<<"3 11 14\n";
    }else if(n<=9)
    {
        cout<<"20 30 40\n";
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
