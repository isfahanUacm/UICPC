#include <bits/stdc++.h>
using namespace std;

// Almost Union-Find

#define num long long int

int n, m, ind[100003];
vector<int> par, ran, siz;
vector<num> sum, val; 

int ufind(int u){
    return (par[u] == u) ? u : (par[u] = ufind(par[u])); 
}

void umerge(int u, int v){
    int i = ufind(u), j = ufind(v);
    if(i == j)
        return;
    if(ran[i] > ran[j]){
        par[j] = i;
        siz[i] += siz[j], siz[j] = 0;
        sum[i] += sum[j], sum[j] = 0;
    }
    else{
        par[i] = j;
        siz[j] += siz[i], siz[i] = 0;
        sum[j] += sum[i], sum[i] = 0;
        if(ran[i] == ran[j])
           ran[j]++; 
    }
}

void urem(int u, int v){
    int i = ufind(u), j = ufind(v);
    if(i == j)
        return;
    siz[i]--, sum[i] -= val[u];
    par.push_back(n), ran.push_back(0), siz.push_back(1);
    sum.push_back(val[u]), val.push_back(val[u]);
    ind[val[u] - 1] = n;
    umerge(n++, j);
}


int main(){
    while(cin >> n >> m){
        par.resize(n), ran.resize(n), siz.resize(n);
        sum.resize(n), val.resize(n);
        for(int i = 0; i < n; i++){
            ind[i] = i;
            par[i] = i, ran[i] = 0, siz[i] = 1;
            sum[i] = val[i] = i + 1; 
        }
        int x, p, q;
        while(m--){
            cin >> x;
            if(x == 1)
                cin >> p >> q, umerge(ind[p-1], ind[q-1]);
            else if(x == 2)
                cin >> p >> q, urem(ind[p-1], ind[q-1]);
            else if(x == 3)
                cin >> p, p = ufind(ind[p-1]), cout << siz[p] << " " << sum[p] << endl;
        }
    }
}