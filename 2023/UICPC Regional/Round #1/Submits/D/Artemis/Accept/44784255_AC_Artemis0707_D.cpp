#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    g--; s--;

    int dist[f + 10];
    memset(dist, -1, sizeof(dist));

    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x + u < f && dist[x + u] == -1) {
            q.push(x + u);
            dist[x + u] = dist[x] + 1;
        }
        if (x - d >= 0 && dist[x - d] == -1) {
            q.push(x - d);
            dist[x - d] = dist[x] + 1;
        }
    }

    if (dist[g] != -1) {
        cout << dist[g] << endl;
    }
    else {
        cout << "use the stairs" << endl;
    }
}