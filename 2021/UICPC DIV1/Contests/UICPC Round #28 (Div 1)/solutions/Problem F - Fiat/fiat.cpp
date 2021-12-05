#include <bits/stdc++.h>
using namespace std;


// Extended Euclid: Solving Linear Diophantine Equation
// ax + by = c has no integral solutions if gcd(a, b) | c is not true
// calculate x0, y0 by this algorithm
// then: x = x0 + (b/gcd(a, b))n, y = y0 − (a/gcd(a, b))n
// Notice: always set a as the larger and b as smaller.
long long int x, y, d; // d = gcd(a, b)
void extendedEuclid(long long int a, long long int b) {
    if (b == 0){ // base case
        x = 1;
        y = 0; 
        d = a;
        return;
    }
    extendedEuclid(b, a % b); // similar as the original gcd
    long long int x1 = y;
    long long int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}


// work to find x in: a.x ≡ 1 mod m
int modularInverse(long long int a, long long int m){
    extendedEuclid(a, m);
    if (d != 1) {
        return -1; // No Solution.
    }
    else {
        return (x % m + m) % m;
    }    
}

int modDivide(long long int a, long long int b, long long int m) 
{ 
    a = a % m; 
    long long int inv = modularInverse(b, m); 
    if (inv == -1)
       return -1; // No Solution!
    else
       return (inv * a) % m; 
}

long long int Cat[100003];
const long long int mod = 1000000007;


int n;

int main()
{
    cin >> n;
    Cat[0] = 1;
    for (int i = 1; i <= n; ++i) {
        Cat [i] = modDivide((((4*i-2)%mod)*(Cat[i-1] % mod)), i+1, mod); 
    }
    cout << Cat[n] << endl;
    return 0;
}

