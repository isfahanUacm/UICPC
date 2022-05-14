
#include <bits/stdc++.h>
using namespace std;

int n, w, h, l;
map<string, int> dist;
char grid[13][13];
pair<int, int> X;
string state;
vector<pair<int, int>> state_v(4);
vector<pair<int, int>> robot_poses(4);
queue<pair<int, string>> q;
pair<int, int> dirs[4] = {
    {0, 1}, {1, 0}, {-1, 0}, {0, -1}
};

bool inrange(int i, int j){
    return i >= 0 && j >= 0 && i < h && j < w;
}

string vectostr(){
    string s = "";
    for(int i = 0; i < n; i++){
        s += to_string(state_v[i].first) + " " + to_string(state_v[i].second);
        if (i != n-1)
            s += ",";
    }
    return s;
}

void strtovec(string s){
    stringstream ss(s);
    string robot_pos;
    int it = 0, it2 = 0;
    while(getline(ss, robot_pos, ',')) {
        stringstream ss2(robot_pos);
        string poss;
        int p[2];
        it2 = 0;
        while(getline(ss2, poss, ' ')) {
            p[it2] = stoi(poss);
            it2++;
        }
        state_v[it] = {p[0], p[1]};
        it++;
    }
}

int main() {
    cin >> n >> w >> h >> l;
    
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            cin >> grid[i][j];
            if (grid[i][j] == 'X'){
                X = make_pair(i, j);
                grid[i][j] = '.';
            }
            else if (grid[i][j] != '.' && grid[i][j] != 'W'){
                state_v[stoi(string(1, grid[i][j])) - 1] = make_pair(i, j);
                grid[i][j] = '.';
            }
        }
    }

    state = vectostr();
    dist[state] = 0;
    q.push({0, state});

    pair<int, string> fr;
    pair<int, int> location;
    int d;
    string cur;
    bool flag = false;

    while(!q.empty()){
        fr = q.front(); q.pop();
        d = fr.first;
        cur = fr.second;
        strtovec(cur);

        for (int i = 0; i < n; i++){
            robot_poses[i] = state_v[i];
            grid[robot_poses[i].first][robot_poses[i].second] = char('0' + i);
        }

        if (robot_poses[0] == X){
            flag = true;
            break;
        }

        if (d == l)
            continue;
        
        for (int i = 0; i < n; i++){
            for (int di = 0; di < 4; di++){
                location = robot_poses[i];
                int s = 1;
                while (inrange(location.first + s * dirs[di].first, location.second + s * dirs[di].second) && grid[location.first + s * dirs[di].first][location.second + s * dirs[di].second] == '.')
                    s++;
                location = {location.first + (s - 1) * dirs[di].first, location.second + (s - 1) * dirs[di].second};

                if (location != robot_poses[i]){
                    for (int ii = 0; ii < n; ii++)
                        state_v[ii] = robot_poses[ii];
                    state_v[i] = location;
                    state = vectostr();
                    if (dist.find(state) == dist.end()){
                        dist[state] = d + 1;
                        q.push({d + 1, state});
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
            grid[robot_poses[i].first][robot_poses[i].second] = '.';
    }
    
    if (flag)
        cout << dist[cur] << endl;
    else
        cout << "NO SOLUTION" << endl;

    return 0;
}