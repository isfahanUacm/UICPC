#include <bits/stdc++.h>
#define ff first
#define all(x) (x).begin(), (x).end()
#define ss second
#define pb push_back
#define int long long
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

vector<int> vis;
vector<vector<int>> adj;
vector<int> dis;
int t = 0;
int bfs(int u)
{
    queue<int> q;
    vector<int> ar;
    q.push(u);
    if (dis[u] != -1)
    {
        return t;
    }
    dis[u] = t;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ar.pb(u);
        int fl = 0;
        for (auto v : adj[u])
        {
            if (dis[v] != -1)
            {
                reverse(all(ar));
                t = dis[u] + 1;
                for (int i = 0; i < ar.size() / 2; ++i)
                {
                    int tmp = dis[ar[i]];
                    dis[ar[i]] = dis[ar[ar.size() - i - 1]];
                    dis[ar[ar.size() - i - 1]] = tmp;
                }
                for (int i = 0; i < ar.size(); ++i)
                {
                    vis.pb(ar[i]);
                }
                return t;
            }

            q.push(v);
            dis[v] = dis[u] + 1;
        }
    }
}

int32_t main()
{
    while (true)
    {
        int n;
        t = 0;
        cin >> n;
        if (!n)
        {
            break;
        }
        vector<pair<int, pair<int, int>>> ed;
        adj.clear();
        vis.clear();
        dis.clear();
        adj.resize(n + 1);
        dis.resize(n + 1);
        for (int i = 2; i <= n; ++i)
        {
            int a, b;
            cin >> a >> b;
            ed.pb({b, {a, i}});
            adj[i].pb(a);
        }
        for (int i = 1; i <= n; ++i)
        {
            dis[i] = -1;
        }
        sort(all(ed));
        dis[1] = 0;
        for (int i = 0; i < ed.size(); ++i)
        {
            t = bfs(ed[i].ss.ss);
        }
        int fl = 0;
        for (int i = 0; i < ed.size(); ++i)
        {
            if (ed[i].ff < dis[ed[i].ss.ss])
            {
                fl = 1;
            }
        }
        if (fl)
        {
            cout << "no" << endl;
            continue;
        }
        cout << "yes" << endl;
        for (auto v : vis)
        {
            cout << v << " ";
        }
        cout << endl;
    }
}