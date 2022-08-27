#include <bits/stdc++.h>
using namespace std;
int parent[2505];
int Rank[2505];
int Size[2505];
int grid[2505][2505];
vector<pair<int, pair<int, int>>> edgeList;

void make_set(){
    for (int i = 0; i < 2505; ++i) {
        parent[i] = i;
        Rank[i] = 0;
        Size[i]=1;
    }
}

int find(int v){
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void join(int u, int v){
    int a, b;
    a = find(u);
    b = find(v);
    if(a == b) return;
    if (Rank[a] < Rank[b]) swap(a, b);
    parent[b] = a;
    Size[a] += Size[b];
    if (Rank[a] == Rank[b]) Rank[a]++;
}

int main(){
    int n, forests, mst = 0;
    vector<pair<int, int>> e;
    cin>>n;
    forests = n;
    make_set();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin>>grid[i][j];
            if (i == j) continue;
            edgeList.push_back({grid[i][j], {i, j}});
        }
    }
    sort(edgeList.begin(), edgeList.end());
    for (int i = 0; i < edgeList.size(); i++){
        if(forests == 1)
            break;
        pair<int, pair<int, int>> front = edgeList[i];
        if(find(front.second.first) !=  find(front.second.second)){
            mst += front.first;
            forests--;
            join(front.second.first, front.second.second);
            e.push_back({front.second.first, front.second.second});
        }
    }
    //cout<<mst;
    for (auto ed : e){
        cout<<ed.first+1<<" "<<ed.second+1<<endl;
    }
}