#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    for(int i=0; i<n; i++)
    {
        int a, b; cin >> a >> b;
        if(a==b) cout << "Square";
        else cout << "Rectangle";
    }
}


int main()
{
    solve();
}