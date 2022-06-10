#include <bits/stdc++.h>
using namespace std;

// Cracking The Safe

map<string, int> dis;
queue<string> bfs;

int main(){
    string s = "";
    char c;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> c, s += c;
    dis[s] = 0;
    bfs.push(s);
    while(!bfs.empty()){
        string u = bfs.front();
        bfs.pop();
        if(u == "000000000"){
            cout << dis[u] << endl;
            return 0;
        }
        for(int x = 0; x < 3; x++)
            for(int y = 0; y < 3; y++){
                char g[3][3];
                for(int i = 0; i < 3; i++)
                    for(int j = 0; j < 3; j++)
                        g[i][j] = u[i * 3 + j];
                for(int i = 0; i < 3; i++)
                    for(int j = 0; j < 3; j++)
                        if(i == x || j == y)
                            g[i][j] = (g[i][j] - '0' + 1) % 4 + '0';
                string v = "";
                for(int i = 0; i < 3; i++)
                    for(int j = 0; j < 3; j++)
                        v += g[i][j];
                if(dis.find(v) == dis.end())
                    dis[v] = dis[u] + 1, bfs.push(v);
            }
    }
    cout << -1 << endl;
}