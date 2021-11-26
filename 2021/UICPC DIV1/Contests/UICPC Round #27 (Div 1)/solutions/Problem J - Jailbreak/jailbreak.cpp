#include <bits/stdc++.h>
using namespace std;

int h, w;
struct point{
    char ch;
    int r, c;
};
point p[10003];
vector<vector<int>> adj(10003, vector<int>());
int dist[10003][3];

int adjr[4]={0, 1, 0, -1};
int adjc[4]={1, 0, -1, 0};

bool inrange(int pr, int pc){
    return 0 <= pr && pr < h && 0 <= pc && pc < w;
}
int st[3];
void bfs(){
    for (int i = 0; i < 3; ++i) {
        queue<int> q;
        dist[st[i]][i] = 0;
        q.push(st[i]);
        while(!q.empty()){
            int pp = q.front();
//            cout<<i<<" "<<pp<<endl;
            q.pop();
            for (auto j : adj[pp]) {
                int d = 0;
                if(p[pp].ch == '#') d = 1;
                if(dist[pp][i]+d<dist[j][i])
                    dist[j][i] = dist[pp][i] + d, q.push(j);
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int cc = 1;
        for (int i = 0; i < 10003; ++i)
            adj[i].clear();
        cin>>h>>w;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j){
                cin>>p[i*w+j].ch, p[i*w+j].r = i, p[i*w+j].c = j;
                if(p[i*w+j].ch == '$')
                    st[cc++] = i*w+j;
            }
        p[h*w].ch = '$', p[h*w].r = h, p[h*w].c = w;
        st[0] = h*w;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if(p[i*w+j].ch=='*') continue;
                if(i==0||i==h-1||j==0||j==w-1)
                    adj[h*w].push_back(i*w+j), adj[i*w+j].push_back(h*w);
                for (int k = 0; k < 4; ++k) {
                    if(inrange(i+adjr[k], j+adjc[k])){
                        if(p[(i+adjr[k])*w+(j+adjc[k])].ch == '*')
                            continue;
                        adj[i*w+j].push_back((i+adjr[k])*w+(j+adjc[k]));
                    }
                }
            }
        }
//        for (int i = 0; i <= h*w; ++i) {
//            cout<< i <<" ("<<p[i].ch<<","<<p[i].r<<","<<p[i].c<<")"<<endl;
//            for(auto j: adj[i]){
//                cout<<"("<<p[j].ch<<","<<p[j].r<<","<<p[j].c<<") ";
//            }
//            cout<<endl;
//        }
        
        
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j <= h*w; ++j)
                dist[j][i] = INT_MAX;
        bfs();
        int res = INT_MAX;
        for (int i = 0; i <= h*w; ++i)
            if(dist[i][0]!=INT_MAX && dist[i][1]!=INT_MAX && dist[i][2]!=INT_MAX){
                if(p[i].ch == '#')
                    res = min(res, dist[i][0]+dist[i][1]+dist[i][2]+1);
                else
                    res = min(res, dist[i][0]+dist[i][1]+dist[i][2]);
            }
        cout<<res<<endl;
    }
    return 0;
}

