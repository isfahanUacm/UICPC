#include <bits/stdc++.h>
using namespace std;

// Tree Shopping

const int maxn = 2e5;

int n, k, a[maxn + 3], segmin[4 * maxn + 3], segmax[4 * maxn + 3];

void build(int v, int tl, int tr){
    if(tl == tr)
        segmin[v] = segmax[v] = a[tl];
    else{
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        segmin[v] = min(segmin[2 * v], segmin[2 * v + 1]);
        segmax[v] = max(segmax[2 * v], segmax[2 * v + 1]);
    }
}

int querymin(int v, int tl, int tr, int l, int r){
    if(l > r)
        return INT_MAX;
    if(l == tl && r == tr)
        return segmin[v];
    int tm = (tl + tr) / 2;
    return min(querymin(2 * v, tl, tm, l, min(tm, r)), querymin(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int querymax(int v, int tl, int tr, int l, int r){
    if(l > r)
        return INT_MIN;
    if(l == tl && r == tr)
        return segmax[v];
    int tm = (tl + tr) / 2;
    return max(querymax(2 * v, tl, tm, l, min(tm, r)), querymax(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n-1);
    int ans = INT_MAX;
    for(int i = 0; i + k - 1 < n ; i++)
        ans = min(ans, querymax(1, 0, n-1, i, i + k - 1) - querymin(1, 0, n-1, i, i + k - 1));
    cout << ans << endl;
}