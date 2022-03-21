/*
 * https://open.kattis.com/problems/treasure
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>

using namespace std;

#define num long long int

num dist[51][51][102], n, m, k;
pair<num, num> s, g;
char grid[51][51];
priority_queue<pair<num, tuple<num, num, num>>,
                vector<pair<num, tuple<num, num, num>>>,
                greater<pair<num, tuple<num, num, num>>>> pq;
map<char, num> cost = {
    {'S', 1}, {'G', 1}, {'.', 1}, {'F', 2}, {'M', 3}, {'#', 200}
};

pair<num, num> mv[4] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

bool isvalid(num i, num j){
    return i >= 0 && i < n && j >= 0 && j < m;
}

int main()
{
    cin >> n >> m >> k;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cin >> grid[r][c];
            if(grid[r][c] == 'S')
                s = {r, c};
            else if (grid[r][c] == 'G')
                g = {r, c};
            for (int i = 0; i <= k; ++i)
                dist[r][c][i] = INT_MAX;
        }
    }
    dist[s.first][s.second][k] = 1;
    tuple<num, num, num> cur(s.first, s.second, k);
    pair<num, tuple<num, num, num>> front = {0, cur};
    num cur_r, cur_c, cur_k, nxt_r, nxt_c, nxt_k;
    num res = INT_MAX;
    pq.push(front);
    while(!pq.empty()){
        front = pq.top();
        pq.pop();
        cur = front.second;
        cur_r = get<0>(cur); cur_c = get<1>(cur); cur_k = get<2>(cur);
        if (g.first == cur_r && g.second == cur_c){
            res = dist[cur_r][cur_c][cur_k];
            break;
        }
        if (dist[cur_r][cur_c][cur_k] < front.first)
            continue;
        for (int i = 0; i < 4; ++i) {
            nxt_r = cur_r + mv[i].first; nxt_c = cur_c + mv[i].second;
            if (!isvalid(nxt_r, nxt_c))
                continue;
            nxt_k = cur_k - cost[grid[nxt_r][nxt_c]];
            if (nxt_k >= 0 && dist[nxt_r][nxt_c][nxt_k] > dist[cur_r][cur_c][cur_k]){
                dist[nxt_r][nxt_c][nxt_k] = dist[cur_r][cur_c][cur_k];
                pq.push({dist[nxt_r][nxt_c][nxt_k], tuple<num, num, num>(nxt_r, nxt_c, nxt_k)});
            }
        }
        if(dist[cur_r][cur_c][k] > dist[cur_r][cur_c][cur_k] + 1){
            dist[cur_r][cur_c][k] = dist[cur_r][cur_c][cur_k] + 1;
            pq.push({dist[cur_r][cur_c][k], tuple<num, num, num>(cur_r, cur_c, k)});
        }
    }
    if (res != INT_MAX)
        cout << res << endl;
    else
        cout << -1 << endl;
    return 0;
}

