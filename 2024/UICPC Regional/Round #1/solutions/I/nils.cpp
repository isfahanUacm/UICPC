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

const ll MAXN = 300001;

int n, m;

set<ll> edges;

int nex[MAXN] = {0};
int pre[MAXN] = {0};

int color(ll i, ll j){
    if(edges.find(i*MAXN+j) == edges.end())return 1;
    return 0;
}

int is_mid(int i){
    if(i == -1 || i == n)return -1;
    if(pre[i] == -1 || nex[i] == n)return 1;
    if(color(i,pre[i]) != color(i,nex[i]))return 2;
    return 0;
}

int mid = 0;
int last = 0;

//
void visualize(){
    int a = 0;
    vi chain;
    while(a != n){
        chain.push_back(a);
        a = nex[a];
    }
    string ab = "AB";
    for(int c1 = 0; c1 < sz(chain)-1; c1++){
        cerr << chain[c1]+1 << " - " << ab[color(chain[c1], chain[c1+1])] << " - "; 
    }
    cerr << chain.back()+1 << "\n";
    cerr << "MID: " << mid+1 << "\n\n";
}
//

void insert(int i){
    int c = color(i, mid);
    if(is_mid(mid) == 1 || c == color(pre[mid], mid)){
        // insert after
        nex[i] = nex[mid];
        nex[mid] = i;
        pre[i] = mid;
        if(nex[i] != n)pre[nex[i]] = i;
        if(nex[i] == n)last = i;
    }
    else{
        // insert before
        pre[i] = pre[mid];
        pre[mid] = i;
        nex[i] = mid;
        if(pre[i] != -1)nex[pre[i]] = i;
    }
    vi candidates = {pre[i], i, nex[i]};
    int best = -1;
    trav(y, candidates){
        int x = is_mid(y);
        if(x >= best){
            best = x;
            mid = y;
        }
    }
    if(best == 1)mid = last;
}

int main() {
    cin >> n >> m;
    rep(c1,0,m){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        edges.insert(a*MAXN+b);
        edges.insert(b*MAXN+a);
    }
    nex[0] = n;
    pre[0] = -1;

    rep(c1,1,n){
        insert(c1);
        //visualize();
    }

    assert(pre[0] == -1);

    int a = 0;
    rep(c1,0,n){
        cout << a+1 << " ";
        a = nex[a];
    }
    cout << "\n";
    return 0;
}
