#include <bits/stdc++.h>
using namespace std;

double l, n, c, lp;

int main(){
    cout << fixed << setprecision(10);
    while(cin >> l >> n >> c){
        if(l == -1 && n == -1 && c == -1)
            break;
        lp = l + l * n * c;
        double lo = 0, hi = l/2;
        while(hi - lo > 1e-6){
            double d = (hi + lo) / 2;
            double r = ((l * l) / 4 + d * d) / (2 * d);
            double lt = 2 * r * asin(l / (2 * r));
            if(lt > lp)
                hi = d;
            else lo = d;
        }
        cout << lo << endl;
    }
}