#include <bits/stdc++.h>

using namespace std;

int find(int i, vector<int> p) {
    while (p[i] != i) {
        i = p[i];
    }
    return i;
}

void kruskalMST(vector<vector<int>>cost, int n) {

    vector<int> parent(n + 1);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int edgeNum = 0;

    while (edgeNum < n - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (find(i, parent) != find(j, parent) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int A = find(a, parent);
        int B = find(b, parent);
        parent[A] = B;
        cout << a << " " << b << "\n";
        edgeNum += 1;

    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }
    kruskalMST(graph, n);
    return 0;
}

