#include <iostream>
using namespace std;
#include "string"
#include "queue"
#include "algorithm"
#include "vector"
#define pii pair<int,int>
#define ld long double

vector<pair<int , pii>> game;
int main(){
    int n; cin>>n;
    for (int i = 0; i < n; i++)
    {
        int t, h; cin>> t >> h;
        int comp = t+h;
        game.push_back({comp, {h, t}});
    }

    sort(game.begin(), game.end());

    int time = 0, count=0;
    for (int i = 0; i < game.size(); i++)
    {
        int h = game[i].second.first;
        int t = game[i].second.second;
        if (time + t <= h)
        {
            time += t;
            count++;
        }
        
    }

    cout<<count;
    
    
}