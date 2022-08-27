#include <bits/stdc++.h>

using namespace std;


int find(int i, const int p[]) {
    while (p[i] != i) {
        i = p[i];
    }
    return i;
}

void temp(int i, int j, int p[]) {
    int a = find(i, p);
    int b = find(j, p);
    p[a] = b;
}

void kruskalMST(int cost[][700], int n) {
    int parent[n + 1];
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

        temp(a, b, parent);
        cout << a << " " << b << "\n";
        edgeNum += 1;

    }
}

int main() {
    int n;
    cin >> n;
    int graph[700][700];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 0) {
                graph[i][j] = 0;
            } else {
                cin >> graph[i][j];
            }
        }
    }
    kruskalMST(graph, n);
    return 0;
}