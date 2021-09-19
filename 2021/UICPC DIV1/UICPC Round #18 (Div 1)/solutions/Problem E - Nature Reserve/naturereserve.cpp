#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10003
#define num long long int
int parent[MAX_N];
int raank[MAX_N];
int N, M, L, S;
bool station[MAX_N];vector<int> stations;
vector<pair<num, pair<int, int>>> edgeList;

void initSets(int n){
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        raank[i] = 0;
    }
}

int findSet(int i){
    if(parent[i] == i)
        return i;
    return parent[i] = findSet(parent[i]);
}

inline bool inSameSets(int i, int j){
    return findSet(i) == findSet(j);
}

void mergeSets(int i, int j){
    int a = findSet(i);
    int b = findSet(j);

    if(a == b)
        return;
    if(raank[a] >= raank[b])
        parent[b] = a;
    else
        parent[a] = b;
    
    if(raank[a] == raank[b])
        raank[a]++;
}

int main()
{
    int t, a, b, w;
    cin>>t;
    while(t--){
        cin>>N>>M>>L>>S;
        edgeList.clear();
        stations.clear();
        fill_n(station, N+1, false);
        for (int i = 0; i < S; ++i) {
            cin>>a;
            station[a] = true;
            stations.push_back(a);
        }
        for (int i = 0; i < M; ++i) {
            cin>>a>>b>>w;
            if(station[a] && station[a] == station[b])
                continue;
            edgeList.push_back({w+L, {a, b}});
        }    
    
        for (int i = 0; i < S; ++i) {
            edgeList.push_back({0, {0, stations[i]}});
        }
        sort(edgeList.begin(), edgeList.end());
        num mstcost = 0;
        initSets(N+1);
        for (int i = 0; i < edgeList.size(); ++i) {
            pair<num, pair<int, int>> front = edgeList[i];
            if(!inSameSets(front.second.first, front.second.second)){
                mstcost += front.first;
                mergeSets(front.second.first, front.second.second);
            }
        }
        cout<<mstcost<<endl;
    }
    return 0;
}
