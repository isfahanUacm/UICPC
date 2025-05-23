#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);


vector<int> adj[100001];

void solve()
{
    int a, b, c, d; cin >> a >> b >> c >> d;

    if(a+b>c && a+c>b && b+c>a) ///abc
    {
        cout << "TRIANGLE";
        return;
    }
    if(a+b>d && a+d>b && b+d>a) ///abd
    {
        cout << "TRIANGLE";
        return;
    }
    if(c+b>d && c+d>b && b+d>c) ///bcd
    {
        cout << "TRIANGLE";
        return;
    }
    if(c+a>d && c+d>a && a+d>c) ///acd
    {
        cout << "TRIANGLE";
        return;
    }


    if(a+b>=c && a+c>=b && b+c>=a) ///abc
    {
        cout << "SEGMENT";
        return;
    }
    if(a+b>=d && a+d>=b && b+d>=a) ///abd
    {
        cout << "SEGMENT";
        return;
    }
    if(c+b>=d && c+d>=b && b+d>=c) ///bcd
    {
        cout << "SEGMENT";
        return;
    }
    if(c+a>=d && c+d>=a && a+d>=c) ///acd
    {
        cout << "SEGMENT";
        return;
    }

    cout << "IMPOSSIBLE";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
//    cin >> n;
    while(n--)
        solve();


    return 0;
}