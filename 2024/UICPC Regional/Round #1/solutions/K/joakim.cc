#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

ll mod = 1e9+9;
ll p = 123123;

struct T {
  ll f = 0, r = 0;
  ll pw = 1;
};
T f(T a, T b) {
  T res;
  res.f = (a.f + b.f*a.pw) % mod;
  res.r = (b.r + a.r*b.pw) % mod;
  res.pw = (a.pw*b.pw) % mod;
  return res;
}

T fromint(int a) { return T{a+123,a+123,p}; }

struct Tree {
  vector<T> s; int n;
  Tree(int n = 0) : s(2*n), n(n) {}

  void update(int pos, T val) {
    for (s[pos += n] = val; pos /= 2;)
      s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
  }
  T query(int b, int e) { // query [b, e)
    T ra, rb;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) ra = f(ra, s[b++]);
      if (e % 2) rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n,q;
  cin>>n>>q;
  n += 5;
  Tree st(n);
  rep(i,0,n) st.update(i, fromint(i));

  vector<vi> comp(n);
  vi where(n);
  rep(i,0,n) where[i] = i, comp[i] = {i};

  auto join = [&](int a, int b){
    a = where[a]; b = where[b];
    assert(a != b);
    if(sz(comp[a]) < sz(comp[b])) swap(a,b);
    for(int x : comp[b]) {
      where[x] = a;
      st.update(x,fromint(a));
      comp[a].emplace_back(x);
    }
  };

  rep(i,0,q) {
    int t;
    cin>>t;
    if(t == 1)  {
      int l, r;
      cin>>l>>r;
      ++r;

      while(true) {
        for(int q = (1<<16); q; q/=2) {
          if(l+q < n && r-q >= 0 && st.query(l,l+q).f == st.query(r-q,r).r) {
            l += q;
            r -= q;
          }
        }
        if(l >= r) break;
        assert(where[l] != where[r-1]);
        join(l,r-1);
        assert(where[l] == where[r-1]);
      }
    }
    else if(t == 2) {
      int l1, r1, l2, r2;
      cin>>l1>>r1>>l2>>r2;
      ++r1, ++r2;
      if(r2-l2 != r1-l1) cout << "Not equal\n";
      else if(st.query(l1,r1).f == st.query(l2,r2).f) cout << "Equal\n";
      else cout << "Unknown\n";
    }
    else assert(false);
  }
}
