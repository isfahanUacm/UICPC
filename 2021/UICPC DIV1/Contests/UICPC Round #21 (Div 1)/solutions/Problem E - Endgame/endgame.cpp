#include <bits/stdc++.h>
using namespace std;

// Endgame

const int threshold = 100;

int n, ax, ay, bx, by;
vector<pair<int, int>> actions;
set<pair<int, int>> aliceReach;
set<pair<int, int>> bobReach;

inline bool bob(int ax, int ay){
    if(bobReach.find({ax, ay}) != bobReach.end())
        return true;
    for(int i = 0; i < n; i++){
        int cx = ax - actions[i].first;
        int cy = ay - actions[i].second;
        if(bobReach.find({cx, cy}) != bobReach.end()){
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> ax >> ay >> bx >> by;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        actions.push_back({x, y});
    }
    for(int i = 0; i < n; i++){
        int x = ax + actions[i].first;
        int y = ay + actions[i].second;
        if(x >= 1 && x <= n && y >= 1 && y <= n){
            aliceReach.insert({x, y});
        }
    }
    if(aliceReach.find({bx, by}) != aliceReach.end()){
        cout << "Alice wins" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        int cx = bx - actions[i].first;
        int cy = by - actions[i].second;
        if(aliceReach.find({cx, cy}) != aliceReach.end()){
            cout << "Alice wins" << endl;
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        int x = bx + actions[i].first;
        int y = by + actions[i].second;
        if(x >= 1 && x <= n && y >= 1 && y <= n){
            bobReach.insert({x, y});
        }
    }
    if(!bob(ax, ay)){
        cout << "tie " << ax << " " << ay << endl;
        return 0;
    }
    if(n <= threshold){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(!(i == ax && j == ay) && !(i == bx && j == by)){
                    if(!bob(i, j)){
                        cout << "tie " << i << " " << j  << endl;
                        return 0;
                    }
                }
    }
    else{
        for(int r = 0; r < 1000; r++){
            int i = rand() % n + 1;
            int j = rand() % n + 1;
            if(!(i == ax && j == ay) && !(i == bx && j == by)){
                if(!bob(i, j)){
                    cout << "tie " << i << " " << j  << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Bob wins" << endl;
}