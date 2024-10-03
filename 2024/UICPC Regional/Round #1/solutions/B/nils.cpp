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

const int MAXN = 300001;

int n;
vector<vi> C(MAXN, vi());
int SS[MAXN] = {0};
int centroid = 0;

int dist[MAXN] = {0};
vi ind;
bool comp(int i, int j){
    return dist[i] > dist[j];
}
// Find distances with BFS. This is just to avoid recursion later
void bfs(){
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        int a = Q.front();
        Q.pop();
        trav(y, C[a]){
            if(y != 0 && dist[y] == 0){
                dist[y] = dist[a]+1;
                Q.push(y);
            }
        }
    }
}

void dfs1(){
    rep(c1,0,n){
        int i = ind[c1];
        int ma = 0;
        trav(y, C[i]){
            if(dist[y] > dist[i]){
                SS[i] += SS[y];
                ma = max(ma, SS[y]);
            }
        }
        SS[i]++;
        ma = max(ma, n-SS[i]);
        if(ma <= n/2){
            centroid = i;
        }
    }
}

vector<vi> subtrees;
vi ANS;

void bfs2(int i, int par){
    queue<pii> Q;
    Q.push({i, par});
    while(!Q.empty()){
        int a = Q.front().first;
        int p = Q.front().second;
        subtrees.back().push_back(a);
        Q.pop();
        trav(y, C[a]){
            if(y != p){
                Q.push({y, a});
            }
        }
    }
}

bool compare_vector(vi &v, vi &u){
    return sz(v) > sz(u);
}

int main() {
    cin >> n;
    rep(c1,0,n-1){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    rep(c1,0,n){
        ind.push_back(c1);
    }
    bfs();
    sort(all(ind), comp);

    dfs1();

    if(sz(C[centroid]) == n-1){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    trav(y, C[centroid]){
        vi temp;
        subtrees.push_back(temp);
        bfs2(y, centroid);
        reverse(all(subtrees.back()));
    }

    ANS.push_back(centroid);
    sort(all(subtrees), compare_vector);
    if(sz(subtrees[1]) == 1){
        ANS.push_back(subtrees.back()[0]);
        subtrees.pop_back();
    }

    priority_queue<pii> pq;
    rep(c1,0,sz(subtrees)){
        pq.push({sz(subtrees[c1]), c1});
    }

    while(!pq.empty()){
        int i = pq.top().second;
        pq.pop();
        ANS.push_back(subtrees[i].back());
        subtrees[i].pop_back();

        if(sz(pq) > 0){
            int j = pq.top().second;
            pq.pop();
            ANS.push_back(subtrees[j].back());
            subtrees[j].pop_back();
            if(sz(subtrees[j]) > 0)pq.push({sz(subtrees[j]), j});
        }

        if(sz(subtrees[i]) > 0)pq.push({sz(subtrees[i]), i});

    }

    trav(y, ANS){
        cout << y+1 << " ";
    }cout << "\n";

    return 0;
}
