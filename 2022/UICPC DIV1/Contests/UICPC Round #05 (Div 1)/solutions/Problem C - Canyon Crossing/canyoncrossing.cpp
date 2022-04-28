#include <bits/stdc++.h>
using namespace std;

#define num long long int

num R, C, K, dist[1003][1003], H[1003][1003];

pair<num, num> dir[4] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

bool inrange(num r, num c){
    return r >= 0 && r < R && c >= 0 && c < C;
}

bool judge(num h){
    
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            dist[i][j] = INT_MAX;
    
    queue<pair<num, pair<num, num>>> q;

    for (int j = 0; j < C; j++){
        if (H[R - 1][j] < h){
            dist[R - 1][j] = 1;
            q.push({1, {R - 1, j}});
        }
        else {
            dist[R - 1][j] = 0;
            q.push({0, {R - 1, j}});
        }
    }

    pair<num, pair<num, num>> cur;
    pair<num, num> pos, nxt;
    num dis;

    while (!q.empty()){
        cur = q.front(); q.pop();
        dis = cur.first;
        pos = cur.second;

        if (dist[pos.first][pos.second] < dis)
            continue;
        
        for (int d = 0; d < 4; d++){
            nxt.first = pos.first + dir[d].first;
            nxt.second = pos.second + dir[d].second;
            
            if (inrange(nxt.first, nxt.second) && dist[nxt.first][nxt.second] > dist[pos.first][pos.second] + ((H[nxt.first][nxt.second] < h) ? 1 : 0)){
                dist[nxt.first][nxt.second] = dist[pos.first][pos.second] + ((H[nxt.first][nxt.second] < h) ? 1 : 0);
                if (dist[nxt.first][nxt.second] <= K)
                    q.push({dist[nxt.first][nxt.second], nxt});
            }
        }
    }

    bool res = false;
    for (int j = 0; j < C; j++){
        res = dist[0][j] <= K;

        if (res)
            break;
    }

    return res;
}

int main(){
    
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> H[i][j];
        }
    }
    
    num lo = 0, hi = 1e9, mid;
    while (lo < hi){
        
        mid = lo + (hi - lo) / 2 + (hi - lo) % 2;
        
        if (judge(mid))
            lo = mid;
        else
            hi = mid - 1;
    }

    cout << lo << endl;

    return 0;
}