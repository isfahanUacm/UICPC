#include <bits/stdc++.h>
using namespace std;

// Forest for the Trees

#define num long long int

num gcd(num a, num b){
    num mi = min(a, b), ma = max(a, b);
    if(!mi)
        return ma;
    return gcd(ma % mi, mi);
}

num xb, yb, x1, y11, x2, y2;

int main(){
    cin >> xb >> yb >> x1 >> y11 >> x2 >> y2;
    num g = gcd(xb, yb);
    if(g == 1){
        cout << "Yes" << endl;
        return 0;
    }
    num k = xb / g, q = yb / g;
    if(k >= x1 && xb - k <= x2 && q >= y11 && yb - q <= y2){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    if(!(k >= x1 && k <= x2 && q >= y11 && q <= y2)){
        cout << k << " " << q << endl;
        return 0;
    }
    num lo = 1, hi = g - 1;
    while(lo < hi){
        num mid = (lo + hi) / 2;
        num x = mid * k, y = mid * q;
        if(x >= x1 && x <= x2 && y >= y11 && y <= y2)
            lo = mid + 1;
        else
            hi = mid;
    }
    cout << lo * k << " " << lo * q << endl;
}