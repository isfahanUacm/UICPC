#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

const ll MOD = 1e9 + 7;
const ll RT = 1e6 + 3;

ll mod_pow(ll b, ll e, ll m) {
  ll res = 1; while(e) {
    if(e & 1) res = (res*b%m+m)%m;
    b *= b; b %= m; e >>= 1; }
  return res; }

struct node {
  int l, r; ll x;
  node() {}
  node(int _l, int _r) : l(_l), r(_r), x(0) { }
  node(int _l, int _r, ll _x) : node(_l,_r) { x = _x; }
  node(node a, node b) : node(a.l,b.r) { x = (a.x + mod_pow(RT, a.r - a.l + 1, MOD) * b.x) % MOD; }
  void update(ll v) { x = v; } };

struct segment_tree {
  int n;
  vector<node> arr;
  segment_tree() { }
  segment_tree(const vector<ll> &a) : n(a.size()), arr(4*n) {
    mk(a,0,0,n-1); }
  node mk(const vector<ll> &a, int i, int l, int r) {
    int m = (l+r)/2;
    return arr[i] = l > r ? node(l,r) :
      l == r ? node(l,r,a[l]) :
      node(mk(a,2*i+1,l,m),mk(a,2*i+2,m+1,r)); }
  node update(int at, ll v, int i=0) {
    int hl = arr[i].l, hr = arr[i].r;
    if(at < hl || hr < at) return arr[i];
    if(hl == at && at == hr) {
      arr[i].update(v); return arr[i]; }
    return arr[i] =
      node(update(at,v,2*i+1),update(at,v,2*i+2)); }
  node query(int l, int r, int i=0) {
    int hl = arr[i].l, hr = arr[i].r;
    l = max(l, hl); r = min(r, hr);
    if(l == hl && r == hr) return arr[i];
    if(r <= arr[2 * i + 1].r) return query(l, r, 2 * i + 1);
    if(l >= arr[2 * i + 2].l) return query(l, r, 2 * i + 2);
    return node(query(l,r,2*i+1),query(l,r,2*i+2)); } };

segment_tree fwd, rev;

struct unionfind {
  vi p; vector<list<int>> grp; int c;
  unionfind(int n) : p(n, -1), c(n) { 
    grp = vector<list<int>>(n);
    for(int i = 0; i < n; ++i) grp[i].push_back(i);
  }
  int find(int x) {
    return p[x] < 0 ? x : p[x] = find(p[x]);
  }
  bool united(int x, int y) {
    return find(x) == find(y);
  }
  void unite(int x, int y) {
    int a = find(x), b = find(y);
    if(a == b) return;
    if(p[a] > p[b]) swap(a, b);
    p[a] += p[b];
    grp[a].splice(grp[a].end(), grp[b]);
    p[b] = a;
    return;
  }
  int size(int x) {
    return -p[find(x)];
  }
};

int n;
unionfind uf(0);

void set_equal(int x, int y) {
    x = uf.find(x); y = uf.find(y);
    if(x == y) return;
    if(uf.size(x) < uf.size(y)) swap(x, y);
    for(int i : uf.grp[y]) {
        fwd.update(i, x);
        rev.update(n - 1 - i, x);
    }
    uf.unite(x, y);
}

void make_equal(int l, int r, int lp, int rp) {
    if(l == r) {
        set_equal(uf.find(l), uf.find(n - 1 - lp));
        return;
    }
    int d = (r - l) / 2;
    if(fwd.query(l, l + d).x != rev.query(lp, lp + d).x) {
        make_equal(l, l + d, lp, lp + d);
    }
    if(fwd.query(l + d + 1, r).x != rev.query(lp + d + 1, rp).x) {
        make_equal(l + d + 1, r, lp + d + 1, rp);
    }
}

int main() {
    int q, l1, l2, r1, r2, t;
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    vector<ll> dat(n);
    for(int i = 0; i < n; ++i) dat[i] = i;
    fwd = segment_tree(dat);
    reverse(dat.begin(), dat.end());
    rev = segment_tree(dat);
    uf = unionfind(n);
    while(q--) {
        cin >> t;
        if(t == 1) {
            cin >> l1 >> r1;
            l1--; r1--;
            make_equal(l1, r1, n - 1 - r1, n - 1 - l1);
        } else {
            cin >> l1 >> r1 >> l2 >> r2;
            l1--; r1--; l2--; r2--;
            if(r1 - l1 != r2 - l2) {
                cout << "Not equal\n";
            } else if(fwd.query(l1, r1).x != fwd.query(l2, r2).x) {
                cout << "Unknown\n";
            } else {
                cout << "Equal\n";
            }
        }
    }
}
