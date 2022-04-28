#include <bits/stdc++.h>

using namespace std;

double d, s;

inline double f(double a){
    return a * cosh(d / (2 * a)) - a - s;
}

int main(){
    cin >> d >> s;
    double lo = 0, hi = 1e9;
    while(1){
        double mid = (lo + hi) / 2;
        double ans = f(mid);
        if(fabs(ans) < 1e-8){
            cout << fixed << setprecision(4) << 2 * mid * sinh(d / (2 * mid)) << endl;
            return 0;
        }
        else if(f(mid) > 0)
            lo = mid;
        else
            hi = mid;
    }
}

