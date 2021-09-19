#include <bits/stdc++.h>
using namespace std;

// Reconstructing Tape Art

const int maxn = 1e5 + 3;

int n;
vector<int> tapes[maxn];
vector<pair<int, int>> colors;
set<int> put;

int main(){
    int c;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> c, tapes[c].push_back(i);
    for(int c = 1; c <= n; c++)
        if(!tapes[c].empty())
            colors.push_back({-(tapes[c].back() - tapes[c].front() + 1), c});
    sort(colors.begin(), colors.end());
    for(pair<int, int> p : colors){
        int c = p.second;
        if(put.upper_bound(tapes[c].front()) != put.upper_bound(tapes[c].back())){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        for(int it : tapes[c])
            put.insert(it);
    }
    cout << colors.size() << endl;
    for(pair<int, int> p : colors){
        int c = p.second;
        cout << tapes[c].front() << " " << tapes[c].back() << " " << c << endl;
    }
}