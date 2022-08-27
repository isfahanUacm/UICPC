#include <iostream>
using namespace std;
#include "string"
#include "queue"
#include "algorithm"
#include "vector"
#define pii pair<int,int>
#define ld long double

vector<pair<ld , pii>> game;
int main(){
    int n; cin>>n;
    for (int i = 0; i < n; i++)
    {
        int t, h; cin>>t>>h;
        ld comp = ( (ld) t  + (ld) h )/2;
        game.push_back({comp, {t, h}});
    }

    sort(game.begin(), game.end());

    int time = 0, count=0;
    for (int i = 0; i < game.size(); i++)
    {
        int t = game[i].second.first;
        int h = game[i].second.second;
        if ((ld)time + (ld)t/2 < (ld)h)
        {
            time += t;
            count++;
        }
        
    }

    cout<<count;
    
    
}