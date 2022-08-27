#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <math.h>
#include <numeric>
using namespace std;

set<pair<int, int>> slv;

// Creating shortcut for an integer pair
typedef pair<int, int> iPair;

struct Graph
{
    int V, E;
    vector< pair<int, iPair> > edges;

    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({ w, {u, v} });
    }

    int kruskalMST();
};

struct DisjointSets
{
    int* parent, * rnk;
    int n;

    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n + 1];
        rnk = new int[n + 1];

        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;

            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        if (rnk[x] > rnk[y])
            parent[y] = x;
        else 
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};


int Graph::kruskalMST()
{
    int mst_wt = 0; 

    sort(edges.begin(), edges.end());

    DisjointSets ds(V);

    vector< pair<int, iPair> >::iterator it;
    for (it = edges.begin(); it != edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if (set_u != set_v)
        {

            slv.insert(make_pair(u + 1, v + 1));
            mst_wt += it->first;

            ds.merge(set_u, set_v);
        }
    }

    return mst_wt;
}

int main()
{

    int n;
    cin >> n;
    Graph g(n, n * n - 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int t;
            cin >> t;
            if (t) g.addEdge(i, j, t);
        }
    }

    int mst_wt = g.kruskalMST();
    for (auto t : slv) cout << t.first << " " << t.second << "\n";
    return 0;
}