#include <iostream>
using namespace std;
#include "string"
#include "map"
#include "algorithm"
#include "vector"
#define pii pair<int,int>
#define ld long double

int n, k;
map <string, vector<int>> name;
vector<pii> all;
vector<string> some;
int dp[(1<<20)][23];

int distance(int x, int y, int i, int j){
    return abs(x-i) + abs(y-j);
}

int cdp(int mask, int pre){
    if (dp[mask][pre] != -1)
    {
        return dp[mask][pre];
    }
    if (mask == (1<<k) - 1)
    {
        return distance(all[pre].first, all[pre].second, 0 , 0);
    }

    int temp = 2147483647;
    for (int  i = 0; i < k; i++)
    {
        if ((mask & (1<<i)) == 0)     
        {
            string q = some[i];
            int mn = 2147483647;
            for(int x : name[q]){
                mn = min(mn, 
                            cdp((mask|(1<<i)), x) +
                             distance(all[x].first, all[x].second, all[pre].first, all[pre].second));
            }
            // dp[(mask|(1<<i))][pre] = mn;
            temp = min(mn , temp);
        }
        
    }
    return dp[mask][pre] = temp;
    
    
    
}

int main(){
    cin >> n;
    all.push_back( {0, 0} );
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        string q;
        cin>> x>> y>> q;
        if(name.find(q) != name.end()){ //exist {
            name[q].push_back(i);
        }
        else{
            name[q].push_back(i);
            k++;
            some.push_back(q);
        }
        all.push_back({x, y});
    }
    for (int i = 0; i < (1<<20); i++)
    {
        for (int j = 0; j < 23; j++)
        {
            dp[i][j] = -1;
        }
        
    }
    cout << cdp(0, 0);    
}