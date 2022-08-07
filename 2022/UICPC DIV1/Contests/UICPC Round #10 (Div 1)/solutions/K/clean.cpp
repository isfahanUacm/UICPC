#include <bits/stdc++.h>
using namespace std;

const int N2 = 500000 + 1;
const int N = 2*N2;
int P[N];
int V[N];
int cnt[N];
 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) cin >> P[i];
    
    for (int v = n; v >= 1; v--) {
        V[v]++;
        V[P[v]] += V[v];
    }
    int centroid = 1;
    for (int v = 2; v <= n; v++) if (2*V[v] >= n) centroid = v;

    int bef = 0;
    int v = centroid;
    while (v) {
        swap(bef, V[v]);
        V[v] = n - V[v];
        v = P[v];
    }
    if (P[centroid]) cnt[V[P[centroid]]]++;
    for (int v = 2; v <= n; v++) if (P[v] == centroid) cnt[V[v]]++;
        
    vector<int> S;
    for (int x = 1; x <= n; x++) {
        while (cnt[x] >= 3) {
            cnt[2*x]++;
            cnt[x] -= 2;
        }
        for (int i = 0; i < cnt[x]; i++) S.push_back(x);
    }
 
    bitset<N2> M(1);
    for (int val : S) M |= (M << val);
 
    long long res = 0;
    for (int i = n/2; i >= 0; --i) {
        if (M[i]) {
            res = ((long long)i) * (n-1-i);
            break;
        }
    }
    for (int v = 1; v <= n; v++) res += V[v];
 
    cout << res << "\n";
}
