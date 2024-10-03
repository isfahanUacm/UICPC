#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

const int MAXN = 100001;

const ll mod = 1000000009;
const ll base = MAXN;

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};

int n,q;

ll EXP[MAXN] = {0};
ll INV[MAXN] = {0};
ll W[MAXN] = {0};

vector<vi> C(MAXN, vi());
int PAR[MAXN] = {0};

FT *ft1, *ft2;
ll F1[MAXN] = {0};
ll F2[MAXN] = {0};

ll get_hash(int i, int j, bool reverse){
    ll sum, inv;
    if(!reverse){
        sum = (ft1->query(j+1) - ft1->query(i)%mod + mod)%mod;
        inv = INV[i];
    }
    else{
        sum = (ft2->query(j+1) - ft2->query(i)%mod + mod)%mod;
        inv = INV[n-j-1];
    }
    return (sum*inv)%mod;
}

void change_parent(int i, int new_p){
    PAR[i] = new_p;
    C[new_p].push_back(i);

    ll new_f1 = (W[new_p]*EXP[i])%mod;
    ft1->update(i,new_f1 - F1[i]);
    F1[i] = new_f1;

    ll new_f2 = (W[new_p]*EXP[n-i-1])%mod;
    ft2->update(i,new_f2 - F2[i]);
    F2[i] = new_f2;
}

void merge(int i, int j){
    i = PAR[i];
    j = PAR[j];
    assert(i != j);
    if(sz(C[j]) > sz(C[i])){
        swap(i, j);
    }
    trav(y, C[j]){
        change_parent(y, i);
    }
    C[j].clear();
}

void palindrome(int x1, int x2, int y2, int y1){
    if(x2 < x1)return;
    if(PAR[x2] != PAR[y2]){
        merge(x2, y2);
        palindrome(x1,x2-1,y2+1,y1);
        return;
    }

    if(get_hash(x1,x2,0) == get_hash(y2,y1,1)){
        return;
    }

    int lo = 0;
    int hi = x2-x1;
    while(lo < hi-1){
        int mid = (lo+hi)/2;
        bool test = (get_hash(x2-mid,x2,0) == get_hash(y2,y2+mid,1));
        if(test){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }

    merge(x2-hi,y2+hi);
    palindrome(x1,x2-hi-1,y2+hi+1,y1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll inv = modpow(base, mod-2);
    ll t1 = 1;
    ll t2 = 1;
    rep(c1,0,MAXN){
        EXP[c1] = t1;
        INV[c1] = t2;
        t1 = (t1*base)%mod;
        t2 = (t2*inv)%mod;
        W[c1] = (ll(rand()) * mod + ll(rand()))%mod; // try to avoid collisions?
    }

    cin >> n >> q;
    ft1 = new FT(n);
    ft2 = new FT(n);

    rep(c1,0,n){
        change_parent(c1,c1);
    }

    rep(c1,0,q){
        int a;
        cin >> a;
        if(a == 1){
            int x,y;
            cin >> x >> y;
            x--;
            y--;
            palindrome(x, (x+y)/2-(y-x+1)%2, (x+y)/2+1, y);
        }
        else{
            int l1,l2,r1,r2;
            cin >> l1 >> r1 >> l2 >> r2;
            l1--;
            r1--;
            l2--;
            r2--;
            if(r2-l2 != r1-l1){
                cout << "Not equal\n";
            }
            else{
                ll h1 = get_hash(l1,r1,0);
                ll h2 = get_hash(l2,r2,0);

                if(h1 == h2){
                    cout << "Equal\n";
                }
                else{
                    cout << "Unknown\n";
                }
            }
        }
    }

    return 0;
}