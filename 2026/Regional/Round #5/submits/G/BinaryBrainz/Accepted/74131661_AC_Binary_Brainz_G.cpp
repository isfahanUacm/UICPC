#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    double a , b , l;
    cin >> a >> b >> l;
    double c=1.5*sqrt(3.0);
    double t=l*l;
    double p=c*t;
    cout<<fixed<<setprecision(6)<<(p/(a*b));
    return 0;
}