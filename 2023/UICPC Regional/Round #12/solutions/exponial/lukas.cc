//Solution by lukasP (Lukáš Poláček)
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

template <class Z> Z euclid(Z a, Z b, Z &x, Z &y) {
    if (b) { Z d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}
template <class Z> inline Z chinese(Z a, Z m, Z b, Z n) {
    Z x, y; euclid(m, n, x, y);
    Z ret = a * (y + m) % m * n + b * (x + n) % n * m;
    if (ret >= m * n) ret -= m * n;
    return ret;
}

vector<int> primes;
int phi(int n) {
    int res = 1;
    for (int x : primes) {
        if (x > n / x) break;
        if (n % x == 0) {
            n /= x;
            res *= x - 1;
            while (n % x == 0) {
                n /= x;
                res *= x;
            }
        }
    }
    if (n > 1) {
        res *= n - 1;
    }
    return res;
}
int pow(int n, int p, int mod) {
    if (p == 0) return 1 % mod;
    long long res = pow(n, p / 2, mod);
    res = (res * res) % mod;
    if (p & 1) res = (res * n) % mod;
    return res;
}
int tower(int n) {
    if (n <= 3) return n - 1;
    if (n == 4) return 9;
    return 1000;
}
int exponial(int n, int m) {
    if (m == 1) {
        return 0;
    }

    long long d = __gcd(n, m);
    while (__gcd(n, m / (int)d) > 1) {
        d *= __gcd(n, m / (int)d);
    }

    int mod = phi(m / d);
    int up = exponial(n - 1, mod);
    long long a = pow(n, up, m / d);
    long long b = pow(n, tower(n), d);
    return chinese(a, m / d, b, d);
}
int main() {
    bitset<100000> p;
    p.set();
    rep(i,2,100000) if (p[i]) {
        primes.push_back(i);
        if (i <= 400) for (int j = i * i; j < 100000; j += i)
            p[j] = false;
    }

    int n, m;
    cin >> n >> m;
    cout << exponial(n, m) << endl;
}
