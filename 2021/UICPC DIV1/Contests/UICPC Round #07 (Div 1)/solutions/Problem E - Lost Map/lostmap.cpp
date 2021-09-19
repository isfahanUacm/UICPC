#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2503
#define num long long int
int parent[MAX_N];
int raank[MAX_N];
int n;
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
    num c;
    cin>>n;
    edgeList.clear();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>c;
            if(i==j)continue;
            edgeList.push_back(make_pair(c, make_pair(i, j)));
        }
    }
    sort(edgeList.begin(), edgeList.end());
    num mstcost = 0;
    vector<pair<int, int>> res;
    initSets(n);
    for (int i = 0; i < edgeList.size(); ++i) {
        pair<num, pair<int, int>> front = edgeList[i];
        if(!inSameSets(front.second.first, front.second.second)){
            res.push_back(make_pair(front.second.first, front.second.second));
            mstcost += front.first;
            mergeSets(front.second.first, front.second.second);
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i].first+1<<" "<<res[i].second+1<<endl;
    }
    
    return 0;
}
