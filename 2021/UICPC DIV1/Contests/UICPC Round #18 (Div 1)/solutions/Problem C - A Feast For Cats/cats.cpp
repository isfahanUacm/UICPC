#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2003
#define num long long int
int parent[MAX_N];
int raank[MAX_N];
int t, m, c, a, b, w;
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
    cin>>t;
    while(t--){
        cin>>m>>c;
        edgeList.clear();
        if(c==1){
            if(m>=1)
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
            continue;
        }
        for (int i = 0; i < c*(c-1)/2; ++i) {
            cin>>a>>b>>w;
            edgeList.push_back({w, {a, b}});
        }
        sort(edgeList.begin(), edgeList.end());
        num mstcost = 0;
        initSets(c);
        for (int i = 0; i < edgeList.size(); ++i) {
            pair<num, pair<int, int>> front = edgeList[i];
            if(!inSameSets(front.second.first, front.second.second)){;
                mstcost += front.first;
                mergeSets(front.second.first, front.second.second);
            }
        }
        if(mstcost+c<=m)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
        return 0;
}
