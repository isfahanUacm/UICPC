#include <bits/stdc++.h>
using namespace std;
#define MAX_N 503
int water[MAX_N][MAX_N];
int h, w, r, c;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int dirr[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dirc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool inrange(int i, int j){
    return i>=0 && j>=0 && i<h && j<w;
}

int main()
{
    cin>>h>>w;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin>>water[i][j];
    cin>>r>>c;r--;c--;
    pq.push({water[r][c], {r, c}});
    pair<int, pair<int, int>> pp;
    pair<int, int> p;
    long long int res=0;
    while(!pq.empty()){
        pp = pq.top(); pq.pop();
        p = pp.second;
        if(water[p.first][p.second]>=0)
            continue;
        water[p.first][p.second]=0;
        res += -pp.first;
        
        for (int i = 0; i < 8; ++i) {
            if(inrange(p.first+dirr[i], p.second+dirc[i]) && water[p.first+dirr[i]][p.second+dirc[i]]<0){
                pq.push({max(pp.first, water[p.first+dirr[i]][p.second+dirc[i]]), {p.first+dirr[i], p.second+dirc[i]}});
            }
        }
    }
    cout<<res<<endl;
    
    return 0;
}

