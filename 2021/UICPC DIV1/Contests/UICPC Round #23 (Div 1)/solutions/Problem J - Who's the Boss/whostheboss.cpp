#include <bits/stdc++.h>
using namespace std;

// Who's the Boss?

int n, q;

struct emp{
    int id, salary, height, index;
    bool operator<(const emp& o) const{
        return this->salary < o.salary;
    }
};

emp emps[100003];

bool cmp(const emp& e1, const emp& e2){
    if(e1.height == e2.height)
        return e1.salary > e2.salary;
    return e1.height > e2.height;
}

map<int, int> gindx;
set<emp> tillnow;
int par[100003];
vector<int> adj[100003];

int subor[100003];

int rec(int u){
    int cnt = 1;
    for(int v : adj[u])
        cnt += rec(v);
    return subor[u] = cnt;
}

int main(){
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> emps[i].id >> emps[i].salary >> emps[i].height;
    sort(emps, emps+n, cmp);
    for(int i = 0; i < n; i++)
        emps[i].index = i, gindx[emps[i].id] = i;
    tillnow.insert(emps[0]);
    for(int i = 1; i < n; i++){
        par[i] = tillnow.upper_bound(emps[i])->index;
        adj[par[i]].push_back(i);
        tillnow.insert(emps[i]);       
    }
    rec(0);
    int id;
    while(q--){
        cin >> id;
        int ind = gindx[id];
        cout << (ind == 0 ? 0 : emps[par[ind]].id) << " " << subor[ind] - 1 << endl;
    }
}