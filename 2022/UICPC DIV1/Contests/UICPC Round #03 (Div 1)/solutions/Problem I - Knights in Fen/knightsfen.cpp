#include <bits/stdc++.h>

using namespace std;

int n;
map<string, int> dist;
string s, tmp;
string src = "111110111100 110000100000";

vector<int> adj[25]={
    {7, 11}, {8, 10, 12}, {5, 9, 11, 13}, {6, 12, 14}, {7, 13},
    {2, 12, 16}, {3, 13, 15, 17}, {0, 4, 10, 14, 16, 18}, {1, 11, 17, 19}, {2, 12, 18},
    {1, 7, 17, 21}, {0, 2, 8, 18, 20, 22}, {1, 3, 5, 9, 15, 19, 21, 23}, {2, 4, 6, 16, 22, 24}, {3, 7, 17, 23},
    {6, 12, 22}, {5, 7, 13, 23}, {6, 8, 10, 14, 20, 24}, {7, 9, 11, 21}, {8, 12, 22},
    {11, 17}, {10, 12, 18}, {11, 13, 15, 19}, {12, 14, 16}, {13, 17}
};


void calc(){
    dist[src] = 0;
    queue<pair<string, int>> q;
    q.push({src, 12});
    pair<string, int> front;
    string nei;
    while(!q.empty()){
        front = q.front();
        q.pop();
        for (auto v: adj[front.second]) {
            nei = front.first;
            nei[front.second] = nei[v];
            nei[v] = ' ';
            if (dist.find(nei) == dist.end() && dist[front.first] < 10){
                dist[nei] = dist[front.first] + 1;
                q.push({nei, v});
            }
        }
    }
}

int main()
{
    calc();
    cin >> n;
    bool first = true;
    while(n--){
        s = "";
        if(first)
            getline(cin, tmp), first = false;
        for (int i = 0; i < 5; ++i) {
            getline(cin, tmp);
            s += tmp;
        }
        if(dist.find(s) != dist.end())
            cout << "Solvable in " << dist[s] << " move(s)." << endl;
        else
            cout << "Unsolvable in less than 11 move(s)." << endl;
        
    }
    return 0;
}

