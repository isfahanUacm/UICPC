#include <bits/stdc++.h>
using namespace std;

#define MAX_N 400003
int parent[MAX_N];
int raank[MAX_N];
map<int, pair<int, int>> mp;
int n, m, x;
vector<pair<int, pair<int, int>>> edgeList;
vector<pair<int,pair<int, int>>> res;
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

int calc_weight(int i, int j){
    
}

int main()
{
    cin>>n;
    int cc = n;
    edgeList.clear();
    res.clear();
    for (int i = 0; i < n; ++i) {
        cin>>m;
        for (int j = 0; j < m; ++j) {
            cin>>x;
            if(mp.find(x)== mp.end())
                mp[x] = {cc++, i};
            edgeList.push_back(make_pair(x, make_pair(i, mp[x].first)));
        }
    }    
    int remain = cc;
    initSets(cc);
    for (int i = 0; i < edgeList.size(); ++i) {
        pair<int, pair<int, int>> front = edgeList[i];
        if(!inSameSets(front.second.first, front.second.second)){
            mergeSets(front.second.first, front.second.second);
            if(mp[front.first].second != front.second.first){
                res.push_back({front.first, {front.second.first, mp[front.first].second}});
            }
            remain--;
            if(remain==1)
                break;
        }
    }
    if(remain!=1)
        cout<<"impossible"<<endl;
    else{
        for (int i = 0; i < res.size(); ++i) {
            cout<<res[i].second.first+1<<" "<<res[i].second.second+1<<" "<<res[i].first<<endl;
        }
    }
    

    return 0;
}
