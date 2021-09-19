#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1003
#define num long long int
int parent[MAX_N];
int raank[MAX_N];
int N, M, P;
bool insecure[MAX_N], vis[MAX_N];
vector<pair<num, pair<int, int>>> edgeList, insedgeList, sus;

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
    int a, b, w;
    cin>>N>>M>>P;
    edgeList.clear();
    insedgeList.clear();
    fill_n(insecure, N, false);
    fill_n(vis, N, false);
    for (int i = 0; i < P; ++i) {
        cin>>a;
        insecure[a-1] = true;
    }
    for (int i = 0; i < M; ++i) {
        cin>>a>>b>>w;
        if(insecure[a-1] && insecure[b-1])
            sus.push_back({w, {a-1, b-1}});
        else if(insecure[a-1] || insecure[b-1])
            insedgeList.push_back({w, {a-1, b-1}});
        else
            edgeList.push_back({w, {a-1, b-1}});
    }
    if(N==1){
        cout<<0<<endl;
        return 0;
    }
    if(N==2 && P==2 && M!=0){
        cout<<sus[0].first<<endl;
        return 0;
    }
    sort(edgeList.begin(), edgeList.end());
    sort(insedgeList.begin(), insedgeList.end());
    num mstcost = 0;
    int cc = N-P;
    initSets(N);
    for (int i = 0; i < edgeList.size(); ++i) {
        pair<num, pair<int, int>> front = edgeList[i];
        if(!inSameSets(front.second.first, front.second.second)){
            mstcost += front.first;
            mergeSets(front.second.first, front.second.second);
            vis[front.second.first] = vis[front.second.second] = true;
            cc--;
        }
    }
    if(cc!=1){
        cout<<"impossible"<<endl;
        return 0;
    }
    if(N-P>1)
    for (int i = 0; i < N; ++i) {
        if(!insecure[i] && !vis[i]){
            cout<<"impossible"<<endl;
            return 0;
        }
    }
    for (int i = 0; i < insedgeList.size(); ++i) {
        pair<num, pair<int, int>> front = insedgeList[i];
        if(!inSameSets(front.second.first, front.second.second)){
            mstcost += front.first;
            mergeSets(front.second.first, front.second.second);
            vis[front.second.first] = vis[front.second.second] = true;
        }
    }
    for (int i = 0; i < N; ++i) {
        if(!vis[i]){
            cout<<"impossible"<<endl;
            return 0;
        }
    }
    cout<<mstcost<<endl;
    
    return 0;
}
