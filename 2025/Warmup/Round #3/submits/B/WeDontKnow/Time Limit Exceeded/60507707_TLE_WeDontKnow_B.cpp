#include <bits/stdc++.h>
using namespace std;

// Fast I/O
struct FastIO {
    FastIO() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastio;

// Typedefs
using ll  = long long;
using ld  = long double;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = vector<int>;
using vll = vector<ll>;

// User-provided macros (overrides)
#define per(t)      for(ll i = 0; i < (t); i++)
#define per2(x,t)   for(ll x = 0; x < (t); x++)
#define per3(x,a,b) for(ll x = (a); x <= (b); x++)
#define rep(t)      for(ll i = (t)-1; i >= 0; i--)
#define rep2(x,t)   for(ll x = (t)-1; x >= 0; x--)
#define rep3(x,a,b) for(ll x = (b); x >= (a); x--)
#define in(x)       cin  >> (x)
#define ot(x)       cout << (x) << '\n'
#define ots(x)      cout << (x) << ' '

// Additional speedup macros
#define F0(i,n)     for(int i=0;i<int(n);++i)
#define F1(i,n)     for(int i=1;i<=int(n);++i)
#define R0(i,n)     for(int i=int(n)-1;i>=0;--i)
#define R1(i,n)     for(int i=int(n);i>=1;--i)
#define each(x,a)   for(auto &x : a)
#define ALL(x)      (x).begin(), (x).end()
#define RALL(x)     (x).rbegin(), (x).rend()
#define SORT(x)     sort(ALL(x))
#define RSORT(x)    sort(RALL(x))
#define UNIQUE(x)   SORT(x), x.erase(unique(ALL(x)), x.end())
#define SZ(x)       int((x).size())
#define mp2(a,b)    make_pair(a,b)
#define mp3(a,b,c)  make_tuple(a,b,c)
#define read(...)   read_input(__VA_ARGS__)
#define write(...)  write_output(__VA_ARGS__)

#ifdef LOCAL
  #define watch(...) debug_vars(#__VA_ARGS__, __VA_ARGS__)
#else
  #define watch(...)
#endif

#define CLAMP(x,l,u) min(max((x),(l)),(u))
#define MIN(a,b)     ((a)<(b)?(a):(b))
#define MAX(a,b)     ((a)>(b)?(a):(b))
#define GCD(a,b)     __gcd((a),(b))
#define LCM(a,b)     ((a)/GCD(a,b)*(b))

#define DEFV(name,val)      vector<ll> name(val)
#define DEFA(name,r,c)      vector<vector<ll>> name(r, vector<ll>(c))

// Variadic I/O implementations
template<typename... Args>
void read_input(Args&... args) {
    (cin >> ... >> args);
}

template<typename... Args>
void write_output(const Args&... args) {
    ((cout << args << ' '), ...);
    cout << '\n';
}

// Input for containers
istream& operator>>(istream& is, vector<int>& v) { for (auto& x : v) is >> x; return is; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template<typename T> istream& operator>>(istream& is, list<T>& l) { for (auto& x : l) is >> x; return is; }
template<typename T> istream& operator>>(istream& is, deque<T>& d) { for (auto& x : d) is >> x; return is; }
template<typename T> istream& operator>>(istream& is, set<T>& s) {
    vector<T> tmp(s.size()); for (auto& x : tmp) is >> x; s = set<T>(ALL(tmp)); return is;
}
template<typename T> istream& operator>>(istream& is, unordered_set<T>& s) {
    vector<T> tmp(s.size()); for (auto& x : tmp) is >> x; s = unordered_set<T>(ALL(tmp)); return is;
}

// Debugging utilities for watch(...)
#ifdef LOCAL
void debug_vars(const char* names) {
    cerr << names << " = (no values)\n";
}
template<typename T, typename... Args>
void debug_vars(const char* names, T&& value, Args&&... args) {
    const char* comma = strchr(names, ',');
    if (comma) {
        cerr.write(names, comma - names)
            << " = " << value << " | ";
        debug_vars(comma + 1, forward<Args>(args)...);
    } else {
        cerr << names << " = " << value << '\n';
    }
}

// Stream printing for containers and pairs
inline int sep_mode = 0; // 0: space, 1: newline

template<typename T>
using is_string = std::is_same<T, std::string>;

template<typename T>
enable_if_t<!is_string<T>::value, std::ostream&>
operator<<(std::ostream& os, const T& container) {
    bool first = true;
    for (const auto& x : container) {
        if (!first) {
            if (sep_mode == 0) os << ' ';
            else os << '\n';
        }
        first = false;
        os << x;
    }
    return os;
}

template<typename A, typename B>
std::ostream& operator<<(std::ostream& os, const std::pair<A, B>& p) {
    if (sep_mode == 0) os << p.first << ' ' << p.second;
    else os << p.first << '\n' << p.second;
    return os;
}
#endif

// Standard macros
#define fi        first
#define se        second
#define sz(x)     int((x).size())
#define all(x)    (x).begin(), (x).end()
#define pb        push_back
#define eb        emplace_back
#define mp        make_pair
#define lb        lower_bound
#define ub        upper_bound
#define bit(x,i)  (((x) >> (i)) & 1)
#define mask(i)   (1LL << (i))
#define in_range(x,a,b) ((x) >= (a) && (x) < (b))

#ifdef LOCAL
  #define dbg(...) do { \
      cerr << __func__ << ':' << __LINE__ << " [" #__VA_ARGS__ "] = "; \
      debug(__VA_ARGS__); \
  } while(0)
#else
  #define dbg(...)
#endif

// Constants
const int INF   = 0x3f3f3f3f;
const ll  LINF  = (ll)4e18;
const int MOD   = 998244353;
const ld  EPS   = 1e-9;
const ld  PI    = acos(-1.0L);

// Random
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
// Random number in [0, x)
inline ll rnd(ll x) { return ll(rng() % x); }

// Modular arithmetic
inline ll mod(ll x, ll m = MOD) { return ((x % m) + m) % m; }
inline ll add(ll a, ll b, ll m = MOD) { a += b; if (a >= m) a -= m; return a; }
inline ll sub(ll a, ll b, ll m = MOD) { a -= b; if (a < 0) a += m; return a; }
inline ll mul(ll a, ll b, ll m = MOD) { return (a * b) % m; }
inline ll modpow(ll base, ll exp, ll mod) {
    base %= mod;
    ll result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
ll modexp(ll a, ll e, ll m = MOD) {
    ll r = 1;
    while (e) {
        if (e & 1) r = mul(r, a, m);
        a = mul(a, a, m);
        e >>= 1;
    }
    return r;
}
ll modinv(ll a, ll m = MOD) { return modexp(a, m-2, m); }

// Precompute factorials and inverses
struct FactInv {
    vector<ll> fact, inv;
    FactInv(int n) {
        fact.resize(n+1); inv.resize(n+1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = mul(fact[i-1], i);
        inv[n] = modinv(fact[n]);
        for (int i = n; i >= 1; --i) inv[i-1] = mul(inv[i], i);
    }
    ll C(int n, int k) {
        if (k < 0 || k > n) return 0;
        return mul(fact[n], mul(inv[k], inv[n-k]));
    }
};

void solve() {
    ll n,m,k;
    read(n,m,k);
    string s;
    in(s);
    ll nums1[m];
    ll nums2[m];
    per(m)
    {
        if(s[i] == 'L')
        {
            nums1[i] = 0;
            nums2[i] = -1;
        }
        if(s[i] == 'R')
        {
            nums1[i] = 0;
            nums2[i] = 1;
        }
        if(s[i] == 'D')
        {
            nums1[i] = 1;
            nums2[i] = 0;
        }
        if(s[i] == 'U')
        {
            nums1[i] = -1;
            nums2[i] = 0;
        }
    }
    ll t = sqrt(m);
    ll p = ceil(double(m)/double(t));
    ll T1[p];
    ll T2[p];
    per(p)
    {
        T1[i] = 0;
        T2[i] = 0;
    }
    per(m)
    {
        T1[i/t] += nums1[i];
        T2[i/t] += nums2[i];
    }
    per(k)
    {
        ll a;
        in(a);
        if(a == 1)
        {
            ll x,y,l,r;
            read(x,y,l,r);
            l--;
            r--;
            ll res1 = 0, res2 = 0;
            ll cur = l;
            while(cur <= r)
            {
                if(cur % t == 0 && cur + t - 1 <= r)
                {
                    res1 += T1[cur/t];
                    res2 += T2[cur/t];
                    cur += t;
                }
                else
                {
                    res1 += nums1[cur];
                    res2 += nums2[cur];
                    cur++;
                }
            }
            res1+=x;
            res2+=y;

            if(res1 > n) ots(n);
            else ots(res1);
            if(res2 > n) ot(n);
            else ot(res2);
        }
        else
        {
            ll a;
            in(a);
            a--;
            char c;
            in(c);
            ll num1, num2;
            if(c == 'L')
            {
                num1 = 0;
                num2 = -1;
            }
            if(c == 'R')
            {
                num1 = 0;
                num2 = 1;
            }
            if(c == 'D')
            {
                num1 = 1;
                num2 = 0;
            }
            if(c == 'U')
            {
                num1 = -1;
                num2 = 0;
            }
            T1[a/t] -= nums1[a];
            T2[a/t] -= nums2[a];
            nums1[a] = num1;
            nums2[a] = num2;
            T1[a/t] += nums1[a];
            T2[a/t] += nums2[a];
        }
    }
}

int main() {
    int T=1;
    read(T);
    while (T--) solve();
    return 0;
}