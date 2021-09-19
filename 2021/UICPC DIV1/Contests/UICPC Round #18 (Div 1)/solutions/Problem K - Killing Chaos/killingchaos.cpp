#include <bits/stdc++.h>
using namespace std;

// Killing Chaos

#define num long long int

inline num m10(num x){
    if(x % 10)
        return x - x % 10 + 10;
    return x;
}

const int maxn = 1e5 + 3;

int n, a[maxn], p[maxn], added[maxn];
int par[maxn], ran[maxn];
num siz[maxn], segs = 0, sum = 0;

void uadd(int u){
    par[u] = u, ran[u] = 0, siz[u] = a[u];
    segs++, sum += m10(a[u]);
}

int ufind(int u){
    return (u == par[u]) ? u : (par[u] = ufind(par[u]));
}

void umerge(int u, int v){
    int i = ufind(u), j = ufind(v);
    if(i == j)
        return;
    segs--;
    sum -= m10(siz[i]) + m10(siz[j]);
    sum += m10(siz[i] + siz[j]);
    if(ran[i] > ran[j]){
        par[j] = i;
        siz[i] += siz[j];
    }
    else{
        par[i] = j;
        siz[j] += siz[i];
        if(ran[i] == ran[j])
            ran[j]++;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> p[i], p[i]--;
    num ans = 0;
    for(int i = n - 1; i >= 0; i--){
        int ind = p[i];
        added[ind] = 1;
        uadd(ind);
        if(ind - 1 >= 0 && added[ind-1])
            umerge(ind, ind - 1);
        if(ind + 1 < n && added[ind+1])
            umerge(ind, ind + 1);
        ans = max(ans, segs * sum);
    }
    cout << ans << endl;   
}