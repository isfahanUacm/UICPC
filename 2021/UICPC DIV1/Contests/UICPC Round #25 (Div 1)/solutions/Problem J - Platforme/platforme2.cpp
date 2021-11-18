#include <bits/stdc++.h>
using namespace std;

// Platforme

int n, h, x, y;
vector<pair<int, pair<int, int>>> a;
vector<pair<int, int>> floors[10003];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> h >> x >> y;
        a.push_back({h, {2 * x, 2 * y}});
        floors[h].push_back({2 * x, 2 * y});
    }
    int ans = 0;
    for(auto p : a){
        int it = p.first - 1, po = p.second.first + 1;
        while(it){
            bool found = false;
            for(auto q : floors[it])
                if(po >= q.first && po <= q.second){
                    found = true;
                    break;
                }
            if(found)
                break;
            it--;
        }
        ans += p.first - it;
        it = p.first - 1, po = p.second.second - 1;
        while(it){
            bool found = false;
            for(auto q : floors[it])
                if(po >= q.first && po <= q.second){
                    found = true;
                    break;
                }
            if(found)
                break;
            it--;
        }
        ans += p.first - it;
    }
    cout << ans << endl;
}