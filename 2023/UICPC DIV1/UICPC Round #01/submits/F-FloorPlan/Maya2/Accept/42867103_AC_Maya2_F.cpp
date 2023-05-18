// C++ program using memoization
#include <bits/stdc++.h>
using namespace std;

const long long int mod = 1e9 + 7;
//int binaryNum[32];

//void octal_to_binary(int octal) {
//    // Converting Octal to Decimal
//    int decimal = 0;
//    int power = 0;
//    while (octal != 0) {
//        decimal += (octal % 10) * pow(8, power);
//        octal /= 10;
//        power++;
//    }

//    // Converting Decimal to Binary
//    int i = 0;
//    while (decimal > 0) {

//        binaryNum[i] = decimal % 2;
//        decimal = decimal / 2;
//        i++;
//    }
//}

int main() {

    long long n;
    cin >> n;
    long long x, y, m, k;
    x = int(sqrt(n));
    m = x; k = 0;
    y = x;


    while (y > 0) {
    if (x * y == n) {
            cout << m << ' ' << k;
        return 0;
    }
    else if (x * y > n){ m--;k++;
        y -= 2;}
    else {
        x += 2;
        m++;k++;
    }
    }


    x = int(sqrt(n)) + 1;
    y = x;
    m = x; k = 0;
    while (y > 0) {
    if (x * y == n) {
        cout << m << ' ' << k;
        return 0;
    }
    else if (x * y > n){ m--;k++;
        y -= 2;}
    else {
        x += 2;
        m++;k++;
    }
    }

    cout << "impossible";

//    int t, n;
//    cin >> t;
//    while(t--) {
//        cin >> n;

//        for(int i = 0; i < 32; ++i) {
//            cout << binaryNum[i];
//        }
//    }

return 0;
}

//////////////////////////////////////////////////////////////////////


//int n; cin >> n;
//int k, m;
//for (int x = 1; x<=n; x++) {
//    k = (x*x - n)/(2*x);
//    m = x - k;
//    if (k <=0 || m <=0) continue;


//    if (m*m - k*k == n) {
//        cout << m << " " << k << '\n';
//        return 0;
//    }
//}
//cout << "impossible" << '\n';
