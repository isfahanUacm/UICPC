#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i,n) for(int i = 0 ; i < n ; i ++)


int gcd(int a, int b)
{
    for(int i =min(a,b); i>0; i--)
    {
        if(a%i==0 && b%i==0)
            return i;
    }
    return 1;
}
bool isPrime(int a)
{
    int s = sqrt(a)+1;
    if(a == 2)
        return true;
    if(a %2 == 0 || a==1)
        return false;
    for(int i=3; i<s; i += 2){
        if(a%i == 0)
            return false;
    }
    return true;
}
void solve()
{
    float x,y ; cin >> x >>y;
    x*= 1e5;
    y*= 1e5;

//    cout << y << endl;
//    cout << (int)y << endl;
    int x1 = x;
    int y1 = y;


    int c = gcd(x1,y1);
    int a = x1/c;
    int b = y1/c;

//    cout << x1 << " " << y1 << " " << a << " " << b << " " << c << endl;

    if(isPrime(a) && isPrime(b))
        cout << a << " " << b << '\n';
    else
        cout << "impossible\n";

}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
    int t ; cin >> t ;
    while(t--)
        solve();

//    cout << __gcd(2, 7);

    return 0;
}
