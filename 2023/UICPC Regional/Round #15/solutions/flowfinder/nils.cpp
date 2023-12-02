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

const int MAXN = 300000;

int n;

vector<vi> G1(MAXN,vi());
vector<vi> G2(MAXN,vi());

bool noleaf[MAXN] = {0};
int parent[MAXN] = {0};
ll answer[MAXN] = {0};

void get_unknown(){
    rep(i2,0,n){
        int i = n-i2-1;
        ll sum = 0;
        rep(c2,0,sz(G1[i])){
            sum += answer[G1[i][c2]];
        }
        if(answer[i] == -1 && noleaf[i])answer[i] = sum;
    }
}

int main()
{
    cin >> n;
    parent[0] = -1;
    rep(c1,0,n-1){
        cin >> parent[c1+1];
        parent[c1+1]--;
        noleaf[parent[c1+1]] = 1;
        G1[parent[c1+1]].push_back(c1+1);
    }
    rep(c1,0,n){
        cin >> answer[c1];
        if(answer[c1] == 0)answer[c1]--;
    }

    // Compress the tree by removing non-leaf ?-vertices.
    rep(c1,0,n){
        if(answer[c1] == -1 && noleaf[c1]){
            rep(c2,0,sz(G1[c1])){
                parent[G1[c1][c2]] = parent[c1];
            }
            parent[c1] = -2;
        }
    }

    // G2 is the compressed tree.
    rep(c1,0,n){
        if(parent[c1] >= 0){
            G2[parent[c1]].push_back(c1);
        }
    }

    // Go through every non-leaf of G2 and try to deduce the values of its children.
    rep(c1,0,n){
        if(parent[c1] != -2 && noleaf[c1]){
            vi unknown;
            ll sum = 0;
            rep(c2,0,sz(G2[c1])){
                int a = G2[c1][c2];
                if(answer[a] != -1){
                    sum += answer[a];
                }
                else{
                    unknown.push_back(a);
                }
            }
            // Sum of known children + #unknown = sum of vertex => unknown children must be 1.
            if(sum + sz(unknown) == answer[c1]){
                rep(c2,0,sz(unknown)){
                    answer[unknown[c2]] = 1;
                }
            }
            else{
                // There is only one unknown child => it can be deduced from the rest.
                if(sz(unknown) == 1){
                    answer[unknown[0]] = answer[c1]-sum;
                }
            }
        }
    }

    // Find the answer for the removed vertices.
    get_unknown();

    // Check that the data is consistent.
    bool fail = 0;
    rep(c1,0,n){
        if(answer[c1] < 1)fail = 1;
        ll sum = 0;
        rep(c2,0,sz(G1[c1])){
            sum += answer[G1[c1][c2]];
        }
        if(sum != answer[c1] && noleaf[c1])fail = 1;
    }
    if(fail){
        cout << "impossible\n";
    }
    else{
        rep(c1,0,n) {
            cout << answer[c1] << "\n";
        }
    }
    return 0;
}
