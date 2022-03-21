#include <bits/stdc++.h>
using namespace std;

namespace Graph {

    template<typename vertex_type = unsigned int, typename weight_type = int>
    struct Tarjan {

        vertex_type V;
        vector<vector<pair<vertex_type, weight_type>>> adjacencyLists;
        const bool directed = true;

        Tarjan(vertex_type V) {
            this->V = V;
            adjacencyLists.resize(V);
        }

        void addEdge(vertex_type source, vertex_type destination, bool twoWay = false, weight_type weight = 1) {
            adjacencyLists[source].push_back(make_pair(destination, weight));
            if(twoWay)
                adjacencyLists[destination].push_back(make_pair(source, weight));
        }

        const vertex_type __UNVISITED__ = 0;

        vertex_type dfsCounter = 1;
        vector<vertex_type> dfsNum, dfsLow;
        vector<bool> currentComponent;
        stack<vertex_type> path;

        vertex_type scComponents = 0;
        vector<vector<vertex_type>> sccList;

        void dfs(){
            dfsNum.assign(V, __UNVISITED__);
            dfsLow.assign(V, __UNVISITED__);
            currentComponent.assign(V, false);
            for(vertex_type v = 0; v < V; v++){
                if(dfsNum[v] == __UNVISITED__){
                    _dfs(v);                 
                }
            }
        }

        void _dfs(vertex_type u){
            dfsLow[u] = dfsNum[u] = dfsCounter++;
            currentComponent[u] = true;
            path.push(u);
            for(auto it: adjacencyLists[u]){
                vertex_type v = it.first;
                if(dfsNum[v] == __UNVISITED__){
                    _dfs(v);
                }
                if(currentComponent[v]){
                    dfsLow[u] = min(dfsLow[u], dfsLow[v]);
                }
            }
            // A strongly connected component found, extracting members:
            if(dfsNum[u] == dfsLow[u]){
                vector<vertex_type> component;
                while(true){
                        vertex_type w = path.top();
                        path.pop();
                        currentComponent[w] = 0;
                        component.push_back(w);
                        if(w == u)
                            break;
                }
                scComponents++;            
                sccList.push_back(component);   
            }

        }
    };
}

using namespace Graph;

string l[103];
set<string> u[103]; 

int main(){
    int n;
    cin >> n;
    string str;
    getline(cin, str);
    for(int i = 0; i < n; i++){
        getline(cin, str);
        stringstream ss(str);
        ss >> l[i] >> l[i];
        u[i].insert(l[i]);
        string x;
        while(ss >> x)
            u[i].insert(x);
    }
    Tarjan<> scc(n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(u[j].find(l[i]) != u[j].end())
                scc.addEdge(i, j);
    scc.dfs();
    int ans = n;
    for(auto scc: scc.sccList)
        ans = min(ans, int(n - scc.size()));
    cout << ans << endl;
}
