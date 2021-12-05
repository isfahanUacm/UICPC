#include<bits/stdc++.h>
using namespace std;

// Managing Packaging

int n;
set<string> names;
map<string, vector<string>> adj;
map<string, int> indeg;
priority_queue<string, vector<string>, greater<string>> kahn;
vector<string> order;

bool first = true;

int main(){
    while(1){
        cin >> n;
        if(!n)
            break;
        if(!first)
            cout << endl;
        first = false;
        names.clear();
        adj.clear();
        indeg.clear();
        order.clear();
        cin.ignore();
        string line, x, y;
        for(int i = 0; i < n; i++){
            getline(cin, line);
            stringstream ss(line);
            ss >> x;
            names.insert(x);
            while(ss >> y)
                adj[y].push_back(x), indeg[x]++;
        }
        for(string name : names)
            if(!indeg[name])
                kahn.push(name);
        while(!kahn.empty()){
            string u = kahn.top();
            kahn.pop();
            order.push_back(u);
            for(string v : adj[u]){
                indeg[v]--;
                if(!indeg[v])
                    kahn.push(v);
            }
        }
        if(order.size() < n)
            cout << "cannot be ordered" << endl;
        else for(string name : order)
            cout << name << endl;
    }
}