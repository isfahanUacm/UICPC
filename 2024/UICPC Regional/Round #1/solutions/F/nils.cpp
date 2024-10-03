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

struct H {
	typedef uint64_t ull;
	ull x; H(ull x=0) : x(x) {}
#define OP(O,A,B) H operator O(H o) { ull r = x; asm \
	(A "addq %%rdx, %0\n adcq $0,%0" : "+a"(r) : B); return r; }
	OP(+,,"d"(o.x)) OP(*,"mul %1\n", "r"(o.x) : "rdx")
	H operator-(H o) { return *this + ~o.x; }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

const int MAXN = 501;
int n;

string A[MAXN][MAXN];

int L[MAXN] = {0};
int tot = 0;

bool check_length(){
    rep(c1,0,n){
        if(L[c1] < 1)return 0;
        rep(c2,0,n){
            if(c1 != c2 && sz(A[c1][c2]) != L[c1] + L[c2])return 0;
        }
    }
    return 1;
}

bool check(vector<string> &ans){
    rep(c1,0,n){
        rep(c2,0,n){
            if(c1 != c2 && ans[c1] + ans[c2] != A[c1][c2])return 0;
        }
    }
    return 1;
}

int main() {
    cin >> n;

    rep(c1,0,n){
        rep(c2,0,n){
            cin >> A[c1][c2];
            if(c1 != c2){
                L[c1] += sz(A[c1][c2]);
            }
        }
        tot += L[c1];
    }

    tot /= (2*n-2);
    if(n > 2){
        rep(c1,0,n){
            L[c1] = (L[c1]-tot) / (n-2);
        }
        if(!check_length()){
            cout << "NONE\n";
            return 0;
        }
        vector<string> ans;
        ans.push_back(A[0][1].substr(0, L[0]));
        rep(c2,1,n){
            ans.push_back(A[0][c2].substr(L[0]));
        }
        if(check(ans)){
            cout << "UNIQUE\n";
            trav(s, ans){
                cout << s << "\n";
            }
        }
        else{
            cout << "NONE\n";
        }

    }
    else{
        string s1 = A[0][1];
        string s2 = A[1][0];
        if(sz(s1) != sz(s2)){
            cout << "NONE\n";
            return 0;
        }
        HashInterval hi1(s1);
        HashInterval hi2(s2);
        int m = sz(s1);

        int i = -1;
        rep(c1,1,m){
            if(hi1.hashInterval(0,c1) == hi2.hashInterval(m-c1,m) && hi1.hashInterval(c1,m) == hi2.hashInterval(0,m-c1)){
                if(i != -1){
                    cout << "MANY\n";
                    return 0;
                }
                i = c1;
            }
        }
        if(i == -1){
            cout << "NONE\n";
        }
        else{
            cout << "UNIQUE\n";
            cout << s1.substr(0, i) << "\n";
            cout << s1.substr(i) << "\n";
        }
    }



    return 0;
}
