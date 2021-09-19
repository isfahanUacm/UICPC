#include <bits/stdc++.h>
using namespace std;

// Chess

vector<pair<int, int>> adj[8][8];
int dis[8][8];
pair<int, int> par[8][8];
queue<pair<int, int>> bfs;
vector<pair<int, int>> path;

int main(){
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++){
            int iti = i - 1, itj = j - 1;
            while(iti >= 0 && itj >= 0)
                adj[i][j].push_back({iti, itj}), iti--, itj--;
            iti = i + 1, itj = j + 1;
            while(iti < 8 && itj < 8)
                adj[i][j].push_back({iti, itj}), iti++, itj++;
            iti = i - 1, itj = j + 1;
            while(iti >= 0 && itj < 8)
                adj[i][j].push_back({iti, itj}), iti--, itj++;
            iti = i + 1, itj = j - 1;
            while(iti < 8 && itj >= 0)
                adj[i][j].push_back({iti, itj}), iti++, itj--;
        }
    int t;
    cin >> t;
    int x1, x2;
    char c1, c2;
    while(t--){
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
                dis[i][j] = INT_MAX;
        cin >> c1 >> x1 >> c2 >> x2;
        int sr = 8 - x1, sc = c1 - 'A', dr = 8 - x2, dc = c2 - 'A';
        dis[sr][sc] = 0;
        par[sr][sc] = {-1, -1};
        bfs.push({sr, sc});
        while(!bfs.empty()){
            int ur = bfs.front().first, uc = bfs.front().second;
            bfs.pop();
            for(pair<int, int> p : adj[ur][uc]){
                int vr = p.first, vc = p.second;
                if(dis[vr][vc] == INT_MAX){
                    dis[vr][vc] = dis[ur][uc] + 1;
                    par[vr][vc] = {ur, uc};
                    bfs.push({vr, vc});
                }
            }
        }
        if(dis[dr][dc] == INT_MAX)
            cout << "Impossible" << endl;
        else{
            cout << dis[dr][dc] << " ";
            path.clear();
            int itr = dr, itc = dc;
            while(itr != -1){
                path.push_back({itr, itc});
                pair<int, int> p = par[itr][itc];
                itr = p.first, itc = p.second;
            }
            for(int i = path.size() - 1; i >= 0; i--)
                cout << char(path[i].second + 'A') << " " << 8 - path[i].first << " ";
            cout << endl;
        }
    }    
}