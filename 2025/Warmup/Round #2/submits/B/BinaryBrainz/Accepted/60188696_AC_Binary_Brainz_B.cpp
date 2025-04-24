#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;

int xs,ys,xf,yf,xp,yp;


void go(){
    cout << 3 << endl;

    if(ys < yp ){
        cout << xs << ' ' << -100000000 << endl;

        if(xf > xp){
            cout << 100000000 << ' ' << -100000000 << endl;
            cout << 100000000 << ' ' << yf;
        }
        else {
            cout << -100000000 << ' ' << -100000000 << endl;
            cout << -100000000 << ' ' << yf;
        }
    }
    else {
        cout << xs << ' ' << +100000000 << endl;
//
        if(xf > xp){
            cout << 100000000 << ' ' << 100000000 << endl;
            cout << 100000000 << ' ' << yf;
        }
        else {
            cout << -100000000 << ' ' << 100000000 << endl;
            cout << -100000000 << ' ' << yf;
        }
    }
}



void solve()
{
    cin >> xs >>ys>>xf>>yf>>xp>>yp;

    int n;

    if(xs < xp && xf < xp ){
        if(ys < yp && yf < yp){
          cout << 1 << endl;
          cout << xf << ' ' << ys;
          return;
        }
        else if(ys > yp && yf > yp){
            cout << 1 << endl;
            cout << xf << ' ' << ys;
            return;
        }
        else {
            go();
            return;
        }


    }
    else if(xs >= xp && xf >= xp){
        if(ys < yp && yf < yp){
            cout << 1 << endl;
            cout << xf << ' ' << ys;
            return;
        }
        else if(ys > yp && yf > yp){
            cout << 1 << endl;
            cout << xf << ' ' << ys;
            return;
        }
        else {
            go();
            return;
        }
    }
    else {
        go();
        return;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
        if (t != 0)
            cout << endl;
    }
}