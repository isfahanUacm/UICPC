#include <bits/stdc++.h>
using namespace std;

int comming[11][15];
int cap[15];
vector<pair<int, int>> adj[11][15];
int n, k, m, u, v, d, z, a, b, c;

int main()
{
    cin >> k >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin>> u >> v >> d >> z;
        adj[d-1][u-1].push_back({v-1, z});
    }
    for (int i = 0; i < k*n; ++i) {
        cin >> a >> b >> c;
        comming[b-1][a-1] += c;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cap[j] += comming[i][j];
            for (pair<int, int> flight : adj[i][j]) {
                if(cap[j] < flight.second){
                    cout << "suboptimal" << endl;
                    return 0;
                }
                cap[j] -= flight.second;
                comming[i+1][flight.first] += flight.second;
            }
        }
    }
    cout << "optimal" <<endl;
    return 0;
}

