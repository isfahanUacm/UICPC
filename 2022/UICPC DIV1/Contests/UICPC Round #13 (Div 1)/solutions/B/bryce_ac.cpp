/*
 * The solution to this problem is a bit of a trick. You first notice the network of roads
 * is a tree. Then the problem is to recover a weighted tree from the distances between every pair
 * of nodes. The smallest distance must be an edge of the tree. Similarly, the next smallest, etc.
 * must be an edge as long as a cycle is not formed.
 *
 * You are actually just running Kruskal's algorithm to find the minimum spanning tree.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef pair<ll, ii> iii;
typedef vector<iii> viii;

ll find(vi &C, ll x) { return (C[x] == x) ? x : C[x] = find(C, C[x]); }
void merge(vi &C, ll x, ll y) { C[find(C, x)] = find(C, y); }

vii kruskal(viii &edges, ll n) {
    sort(edges.begin(), edges.end());

    vi uf(n);
    for (ll i = 0; i < n; ++i)
        uf[i] = i;

    vii MST;
    for (ll i = 0; i < edges.size(); ++i) {
        ll u = edges[i].second.first;
        ll v = edges[i].second.second;

        if (find(uf, u) != find(uf, v)) {
            merge(uf, u, v);
            MST.push_back(ii(u, v));
        }
    }
    return MST;
}

int main() {
    ll n;
    cin >> n;

    viii edges;

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            ll cost;
            cin >> cost;
            edges.push_back(iii(cost, ii(i, j)));
        }
    }

    vii ans = kruskal(edges, n);
    for (ll i = 0; i < ans.size(); ++i) {
        cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
    }
}
