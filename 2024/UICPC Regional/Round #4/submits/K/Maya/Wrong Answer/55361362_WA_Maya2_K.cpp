#include <bits/stdc++.h>
using namespace std;

template <typename M>
struct Modular {
public:
    using Type = typename decay<decltype(M::value)>::type;

    constexpr Modular() : value() {}
    template <typename T>
    Modular(const T &x) {
        value = normalize(x);
    }

    const Type operator()() const { return value; }
    template <typename T>
    explicit operator T() const { return static_cast<T>(value); }
    constexpr static Type mod() { return M::value; }

    template <typename T>
    static Type normalize(const T &x) {
        Type v;
        if (-mod() <= x && x < mod()) {
            v = static_cast<Type>(x);
        }
        else {
            v = static_cast<Type>(x % mod());
        }
        if (v < 0) {
            v += mod();
        }
        return v;
    }

    Modular& operator++() { return *this += 1; }
    Modular& operator--() { return *this -= 1; }
    Modular operator++(int) { Modular res(*this); *this += 1; return res; }
    Modular operator--(int) { Modular res(*this); *this -= 1; return res; }
    Modular operator-() const { return Modular(-value); }

    Modular& operator+=(const Modular &other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
    template <typename T> Modular& operator+=(const T &other) { return *this += Modular(other); }

    Modular& operator-=(const Modular &other) { if ((value -= other.value) < 0) value += mod(); return *this; }
    template <typename T> Modular& operator-=(const T &other) { return *this -= Modular(other); }

    template <typename T = M>
    typename enable_if<is_same<typename Modular<T>::Type, int>::value, Modular>::type& operator*=(const Modular &other) {
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(other.value));
        return *this;
    }
    template <typename T = M>
    typename enable_if<is_same<typename Modular<T>::Type, int64_t>::value, Modular>::type& operator*=(const Modular &other) {
        int64_t q = int64_t(static_cast<long double>(value) * other.value / mod());
        value = normalize(value * other.value - q * mod());
        return *this;
    }
    template <typename T = M>
    typename enable_if<!is_integral<typename Modular<T>::Type>::value, Modular>::type& operator*=(const Modular &other) {
        value = normalize(value * other.value);
        return *this;
    }

    Modular& operator/=(const Modular &other) { return *this *= inverse(other); }

    template <typename T> friend Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }
    template <typename T, typename U> friend Modular<T> operator+(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) += rhs; }
    template <typename T, typename U> friend Modular<T> operator+(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }
     
    template <typename T> friend Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }
    template <typename T, typename U> friend Modular<T> operator-(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
    template <typename T, typename U> friend Modular<T> operator-(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }
     
    template <typename T> friend Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }
    template <typename T, typename U> friend Modular<T> operator*(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
    template <typename T, typename U> friend Modular<T> operator*(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }
     
    template <typename T> friend Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }
    template <typename T, typename U> friend Modular<T> operator/(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
    template <typename T, typename U> friend Modular<T> operator/(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

    template <typename T> friend bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value == rhs.value; }
    template <typename T, typename U> friend bool operator==(const Modular<T> &lhs, U rhs) { return lhs == Modular<T>(rhs); }
    template <typename T, typename U> friend bool operator==(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) == rhs; }

    template <typename T> friend bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) { return !(lhs == rhs); }
    template <typename T, typename U> friend bool operator!=(const Modular<T> &lhs, U rhs) { return !(lhs == rhs); }
    template <typename T, typename U> friend bool operator!=(U lhs, const Modular<T> &rhs) { return !(lhs == rhs); }

    template <typename T> friend bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value < rhs.value; }
    template <typename T> friend bool operator>(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value > rhs.value; }
    template <typename T> friend bool operator<=(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value <= rhs.value; }
    template <typename T> friend bool operator>=(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value >= rhs.value; }

    template <typename U, typename T>
    friend U& operator<<(U &stream, const Modular<T> &number) {
        return stream << number();
    }

    template <typename U, typename T>
    friend U& operator>>(U &stream, Modular<T> &number) {
        typename common_type<typename Modular<T>::Type, int64_t>::type x;
        stream >> x;
        number.value = Modular<T>::normalize(x);
        return stream;
    }

    template <typename T, typename U>
    friend Modular<T> power(Modular<T> a, U b) {
        assert(b >= 0);
        Modular<T> res = 1;
        while (b) {
            if (b & 1) {
                res *= a;
            }
            a *= a;
            b >>= 1;
        }
        return res;
    }

    template<typename T>
    friend Modular<T> inverse(const Modular<T> &a) {
        assert(a.value != 0);
        return power(a, mod() - 2);
    }

    template <typename T>
    friend string to_string(const Modular<T> &number) {
      return to_string(number());
    }

private:
    Type value; 
};

//constexpr int MOD = 998244353;
constexpr int MOD = 1000000007;
using Mint = Modular<integral_constant<decay<decltype(MOD)>::type, MOD>>;

/*
// Dynamic Modular
using ModType = int;
struct VarMod { static ModType value; };
ModType VarMod::value = 1000000007;
ModType &MOD = VarMod::value;
using Mint = Modular<VarMod>;
*/

struct Comb {
    int n;
    vector<Mint> _fact;
    vector<Mint> _inv_fact;
    vector<Mint> _inv;
    
    Comb() : n{0}, _fact{1}, _inv_fact{1}, _inv{0} {}
    Comb(int _n) : Comb() {
        init(_n);
    }
    
    void init(int m) {
        if (m <= n) {
            return;
        }
        _fact.resize(m + 1);
        _inv_fact.resize(m + 1);
        _inv.resize(m + 1);
        
        for (int i = n + 1; i <= m; i++) {
            _fact[i] = _fact[i - 1] * i;
        }
        _inv_fact[m] = inverse(_fact[m]);
        for (int i = m; i > n; i--) {
            _inv_fact[i - 1] = _inv_fact[i] * i;
            _inv[i] = _inv_fact[i] * _fact[i - 1];
        }
        n = m;
    }
    
    Mint fact(int m) {
        if (m > n) {
            init(2 * m);
        }
        return _fact[m];
    }
    Mint inv_fact(int m) {
        if (m > n) {
            init(2 * m);
        }
        return _inv_fact[m];
    }
    Mint inv(int m) {
        if (m > n) {
            init(2 * m);
        }
        return _inv[m];
    }
    Mint comb(int m, int k) {
        if (k < 0 || k > m) {
            return 0;
        }
        return fact(m) * inv_fact(k) * inv_fact(m - k);
    }
} comb;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, h;
    cin >> n >> h;

    long long sss = 0;
    Mint ans = comb.fact(n), sum = 0;
    int rem = n, prv = 0;
    for (int i = 0; i < h; i++) {
        int k;
        cin >> k;
        sss += k;
        rem -= k;
        ans -= (comb.fact(prv + k) - sum) * comb.fact(rem);
        sum += (comb.fact(k));
        prv += k;
    }
    if (sss == n) {
        cout << 0 << '\n';
    } else {
        cout << ans << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
