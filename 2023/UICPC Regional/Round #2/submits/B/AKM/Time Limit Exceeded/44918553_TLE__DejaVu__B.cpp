//In thename of Allah
#include<bits/stdc++.h>

using namespace std ;

#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjacencyList;
    vector<int> path;
    vector<bool> visited;

public:
    Graph(const vector<pair<int, int>>& edges) {
        int numVertices = 0;
        for (auto edge : edges) {
            numVertices = max(numVertices, edge.first + 1);
            numVertices = max(numVertices, edge.second + 1);
        }

        adjacencyList.resize(numVertices);
        visited.resize(numVertices, false);

        for (auto edge : edges) {
            adjacencyList[edge.first].push_back(edge.second);
            adjacencyList[edge.second].push_back(edge.first);
        }
    }

    bool hamiltonianPath(int currentVertex) {
        visited[currentVertex] = true;
        path.push_back(currentVertex);

        if (path.size() == adjacencyList.size()) {
            return true;
        }

        for (int nextVertex : adjacencyList[currentVertex]) {
            if (!visited[nextVertex]) {
                if (hamiltonianPath(nextVertex)) {
                    return true;
                }
            }
        }

        visited[currentVertex] = false;
        path.pop_back();

        return false;
    }

    vector<int> findHamiltonianPath() {
        if (hamiltonianPath(0)) {
            return path;
        }

        return {};
    }
};

int main() {
    int t ;
    cin >> t ;
    int n , m , a ,b  ;
    vector<pair<int, int>> edges  ;
    for(int i = 0 ; i<t ; i++){
        cin >> n >> m ;
        edges.clear() ;
        for(int j=0 ; j<n ; j++){
            cin >> a >> b ;
            edges.push_back(make_pair(a , b)) ;
        }
        Graph graph(edges);
        vector<int> hamiltonianPath = graph.findHamiltonianPath();

        if (!hamiltonianPath.empty())
            cout << "successful hashing\n" ;
        else
            cout << "rehash necessary\n" ;

    }
    return 0;
}
