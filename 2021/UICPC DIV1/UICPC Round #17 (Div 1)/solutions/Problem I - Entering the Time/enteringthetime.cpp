#include <bits/stdc++.h>
using namespace std;

unordered_set<string> visited;
string current, target;
map<string, string> parent;
int change[2] = {1, -1};

bool validate(string x){
    int a, b, c ,d, h, m;
    a = x[0]-'0', b = x[1]-'0', c = x[3] - '0', d = x[4] - '0';
    h = a * 10 + b; m = c * 10 + d;
    return (h < 24) && (h >= 0) && (m < 60) && (m >=0);
}

int main()
{
    cin >> current >> target;
    queue<string> q;
    parent[current] = current;
    q.push(current);
    string fro;
    while(!q.empty()){
        fro = q.front(); q.pop();
        if(fro == target)
            break;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 5; ++j) {
                if(j==2)
                    continue;
                string nxt = fro;
                nxt[j] = char((((fro[j]-'0') + change[i] + 10) % 10)+'0');
                if(validate(nxt) && visited.find(nxt) == visited.end()){
                    visited.insert(nxt);
                    parent[nxt] = fro;
                    q.push(nxt);
                }
            }
        }
    }
    string pre = target;
    vector<string> res;
    while(pre != current){
        res.push_back(pre);
        pre = parent[pre];
    }
    res.push_back(current);
    cout << res.size() << endl;
    for (int i = res.size()-1; i >= 0; --i) {
        cout << res[i] << endl;
    }
    return 0;
}
