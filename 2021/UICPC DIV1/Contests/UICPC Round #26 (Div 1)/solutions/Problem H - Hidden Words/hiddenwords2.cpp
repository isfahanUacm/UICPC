#include <bits/stdc++.h>
using namespace std;

// Hidden Words

class trie{
    public:
    trie* adj[26+3];
    trie* parent = nullptr;
    bool terminal = false;

    trie(){
        fill_n(adj, 26, nullptr);
    }

    trie(trie* parent){
        fill_n(adj, 26, nullptr);
        this->parent = parent;
    }
};

trie* root = new trie();

inline void trie_insert(string s){
    trie* t = root;
    for(int i = 0; i < s.size(); i++){
        int ind = s[i] - 'A'; // 'a' for lowercase
        if(t->adj[ind] == nullptr)
            t->adj[ind] = new trie(t);
        t = t->adj[ind];
    }
    t->terminal = true;
}

int h, w, n;
char g[13][13];
string s;
map<string, int> dict;

bool vis[13][13];
set<string> ans;

int adjR[4]{0, 0, -1, 1};
int adjC[4]{1, -1, 0, 0};

string tmp = "";

void track(int i, int j){
    if(root->terminal)
        ans.insert(tmp);
    vis[i][j] = true;
    for(int k = 0; k < 4; k++){
        int x = i + adjR[k], y = j + adjC[k];
        if(x >= 0 && x < h && y >=0 && y < w && !vis[x][y] && root->adj[g[x][y] - 'A'] != nullptr){
            root = root->adj[g[x][y] - 'A'];
            tmp.push_back(g[x][y]);
            track(x, y);
            tmp.pop_back();
            root = root->parent;
        }
    }
    vis[i][j] = false;
}


int main(){
    cin >> h >> w;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            cin >> g[i][j];
    cin >> n;
    while(n--)
        cin >> s, dict[s]++, trie_insert(s);
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            if(root->adj[g[i][j] - 'A'] != nullptr){
                root = root->adj[g[i][j] - 'A'];
                tmp.push_back(g[i][j]);
                track(i, j);
                tmp.pop_back();
                root = root->parent;
            }
    int cnt = 0;
    for(string s : ans)
        cnt += dict[s];
    cout << cnt << endl;
}