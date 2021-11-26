#include <bits/stdc++.h>
using namespace std;

// Mega Inversions

#define num long long int

const int maxn = 1e5 + 3;
int n;
int a[maxn];
num t[4 * maxn];
num small[maxn], large[maxn];

void update(int v, int tl, int tr, int pos){
    t[v]++;
    if(tl == tr)
        return;
    int tm = (tl + tr) / 2;
    if(pos <= tm)
        update(2 * v, tl, tm, pos);
    else
        update(2 * v + 1, tm + 1, tr, pos);
}

num query(int v, int tl, int tr, int l, int r){
    if(l > r)
        return 0;
    if(l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return query(2 * v, tl, tm, l, min(tm, r)) + query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++){
        large[i] = query(1, 0, n, a[i] + 1, n);
        update(1, 0, n, a[i]);
    }
    fill_n(t, 4 * maxn, 0);
    for(int i = n - 1; i >= 0; i--){
        small[i] = query(1, 0, n, 0, a[i] - 1);
        update(1, 0, n, a[i]);
    }
    num ans = 0;
    for(int i = 1; i < n - 1; i++)
        ans += large[i] * small[i];
    cout << ans << endl;
}