#include <bits/stdc++.h>
using namespace std;

int minKey(int V, int key[], bool mstSet[]){
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    }
    return min_index;
}

void printMST(int V, int parent[], int graph[][300]){
    for (int i = 1; i < V; i++) {
        cout<< parent[i] + 1 << " " << i + 1 << "\n";
    }
}

void primeMST(int V, int graph[][300]){
    int parent[V];

    int key[V];

    bool  mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX, mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(V, key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v]==false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
        }

        
    }
    printMST(V, parent, graph);
}
int main() {
    int n;
    cin >> n;
    int graph[300][300];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    primeMST(n, graph);
    return 0;
}