#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    int cnt = 0;
    if (n <= 1)
        return false;
    else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                cnt++;
        }
        if (cnt > 0)
            return false;
        else
            return true;
    }
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string x, y;
        cin.ignore();
        cin >> x;
        cin.ignore();
        cin >> y;

        int a=0,b=0,pTenA=0,pTenB=0;
        for(int i=0;i<x.length();++i) {
            if(x[i]=='.') {
                pTenA = x.length() - 1 - i;
            }
            else {
                a = a * 10+(x[i] - '0');
            }
        }
        for(int i=0;i<y.length();++i) {
            if(y[i]=='.') {
                pTenB = y.length() - 1 - i;
            }
            else {
                b = b * 10+(y[i] - '0');
            }
        }

        if (pTenA > pTenB) {
            b *= pow(10, pTenA);
        } else if (pTenA < pTenB) {
            a *= pow(10, pTenB);
        }

        int bm = __gcd(a, b);
        a /= bm;
        b /= bm;

        if (is_prime(a) && is_prime(b)) {
            cout << a << " " << b;
        } else {
            cout << "impossible";
        }
        cout << endl;
    }

    return 0;
}
