#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, int> pbb;
typedef tuple<int, bool, bool> tibb;

bool dfs(vector<vector<int>>& graph, vector<int>& places, int number, vector<int>& vis) {
    vector<int> hash_res = graph[number];
    for (auto hash : hash_res) {
        if (vis[hash])
            continue;
        vis[hash] = true;
        if (places[hash] < 0 || dfs(graph, places, places[hash], vis)) {
            places[hash] = number;
            return true;
        }
    }
    return false;
}

int main() {
    int b;
    cin >>b;
    for (int i = 0; i < b; ++i) {
        int numbers, table;
        cin >> numbers >> table;

        vector<vector<int>> v(numbers);

        for (int j = 0; j < numbers; ++j) {
            int a1, a2;
            cin >>a1>>a2;
            v[j].push_back(a1);
            v[j].push_back(a2);
        }
        vector<int> places(table, -1);

        bool is_ok= true;

        for (int j = 0; j < numbers; ++j) {
            vector<int> vis(table, false);
            if (! dfs(v, places, j, vis)){
                is_ok = false;
                break;
            }
        }
        if (is_ok) {
            cout << "successful hashing" << endl;
        } else {
            cout << "rehash necessary" << endl;
        }
    }
    return 0;
}
