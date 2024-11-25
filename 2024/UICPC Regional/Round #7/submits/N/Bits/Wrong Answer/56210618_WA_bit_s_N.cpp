#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s; cin >> s;
    int a = s[0] - '0';
    int b = s[2] - '0';

    if(a > b)
        cout << s << "\n";
    else if(b > a)
        cout << a << '<' << b << '\n';
    else if(b == a)
        cout << a << '=' << b << '\n';

}

int main()
{
    int n = 1;
    cin >> n;
    while(n--)
        solve();


    return 0;
}
