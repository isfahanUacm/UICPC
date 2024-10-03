#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i = (a); i < (b); ++i)

ll mod_pow(ll b, ll e, ll m) {
  ll res = 1;
  while (e) {
    if(e & 1) {
        __int128 mul = res; mul *= b;
        res = mul % m;
    }
    __int128 sq = b; sq *= b;
    b = sq % m;
    e >>= 1; }
  return res; }

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll rho(ll n) {
  vector<ll> seeds = {2,3,5,7,11,13,1031};
  for(ll seed : seeds) {
  ll d = 1, x = seed, y = seed, k = 2;
    while(d == 1) {
      for(int i = 1; i <= k && (d <= 1); ++i) {
        __int128 sq = x; sq *= x; sq++;
        x = sq % n;
        d = gcd(abs(x - y), n);
      } k *= 2; y = x; }
    if(d != n) return d; } return 1; }

bool is_probable_prime(ll n, int k) {
  if (~n & 1) return n == 2;
  if (n <= 3) return n == 3;
  int s = 0; ll d = n - 1;
  while (~d & 1) d >>= 1, s++;
  while (k--) {
    __int128 m1 = n - 3; m1 *= rand(); m1 /= RAND_MAX;
    ll a = m1 + 2;
    ll x = mod_pow(a, d, n);
    if (x == 1 || x == n - 1) continue;
    bool ok = false;
    rep(i,0,s-1) {
      __int128 sq = x; sq *= x;
      x = sq % n;
      if (x == 1) return false;
      if (x == n - 1) { ok = true; break; }
    }
    if (!ok) return false;
} return true; }

vector<pair<int,ll>> factorize(ll n) {
    vector<ll> res, todo;
    todo.push_back(n);
    while(todo.size() > 0) {
        ll cur = todo.back();
        todo.pop_back();
        if(is_probable_prime(cur, 5)) res.push_back(cur);
        else {
            ll d = rho(cur);
            todo.push_back(d);
            todo.push_back(cur / d);
        }
    }
    sort(res.begin(), res.end());
    vector<pair<int,ll>> ret;
    for(ll x : res) {
        if(ret.empty() || ret.back().second != x) ret.push_back(make_pair(1, x));
        else ret.back().first++;
    }
    return ret;
}

bool gauss(vector<pair<int,ll>> &fac) {
    for(pair<int,ll> q : fac) {
        if(q.first % 2 == 0) continue;
        if(q.second % 4 != 3) continue;
        return false;
    }
    return true;
}

pair<ll,ll> join(pair<ll,ll> ab, pair<ll,ll> cd) {
    if(ab.first * cd.first == ab.second * cd.second) {
        ll x = ab.first * cd.first + ab.second * cd.second;
        ll y = abs(ab.first * cd.second - ab.second * cd.first);
        return make_pair(x, y);
    }
    ll x = abs(ab.first * cd.first - ab.second * cd.second);
    ll y = ab.first * cd.second + ab.second * cd.first;
    return make_pair(x, y);
}

int main() {
    ll n, k = 1; cin >> n;
    auto fac = factorize(n * n + k);
    while(!gauss(fac)) {
        k++;
        fac = factorize(n * n + k);
    }
    pair<ll,ll> cur = make_pair(0, 1);
    for(pair<int,ll> q : fac) {
        if(q.second == 2) {
            for(int i = 0; i < q.first; ++i) cur = join(cur, make_pair(1, 1));
        } else if(q.second % 4 == 1) {
            ll a, b;
            for(ll i = 1; i * i < q.second; ++i) {
                ll b2 = q.second - i * i;
                b = round(sqrt(b2));
                if(b * b == b2) {
                    a = i;
                    break;
                }
            }
            for(int i = 0; i < q.first; ++i) cur = join(cur, make_pair(a, b));
        } else {
            for(int i = 0; i < q.first / 2; ++i) cur = join(cur, make_pair(0, q.second));
        }
    }
    cout << cur.first << ' ' << cur.second << endl;
}
