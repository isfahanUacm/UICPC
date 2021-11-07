#include <bits/stdc++.h>
using namespace std;

#define MAX_N 503
int parent[MAX_N];
int raank[MAX_N];
int t, n, s;
double x, y;
pair<double, double> points[MAX_N];
vector<pair<double, pair<int, int>>> edgeList;

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

double calc_weight(int i, int j){
    return sqrt((points[i].first - points[j].first)*(points[i].first - points[j].first) + (points[i].second - points[j].second) * (points[i].second - points[j].second));
}

int main()
{
    cin>>t;
    while(t--){
        cin>>s>>n;
        edgeList.clear();
        for (int i = 0; i < n; ++i) {
            cin>>points[i].first>>points[i].second;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(i==j)continue;
                edgeList.push_back(make_pair(calc_weight(i, j), make_pair(i, j)));
            }
        }
        sort(edgeList.begin(), edgeList.end());
        double mstcost = 0, res = 0;
        int cc = n;
        initSets(n);
        for (int i = 0; i < edgeList.size(); ++i) {
            pair<double, pair<int, int>> front = edgeList[i];
            if(!inSameSets(front.second.first, front.second.second)){
                mstcost += front.first; res = front.first;
                mergeSets(front.second.first, front.second.second);
                cc--;
                if(cc==s)
                    break;
            }
        }
        printf("%.2f\n", res);
    }
    return 0;
}
