#include <bits/stdc++.h>
using namespace std;

#define num long long int

int s;
set<int> ending;
vector<int> adjs[403];
num dp[403];

num cdp(int u){
    if(dp[u] != -1)
        return dp[u];
    if(ending.find(u) != ending.end())
        return dp[u] = 1;
    num ans = 0;
    for(int v : adjs[u])
        ans += cdp(v);
    return dp[u] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        for(int i = 0; i <= 400; i++)
            adjs[i].clear();
        ending.clear();
        for(int i = 0; i < s; i++){
            int x;
            string y; 
            cin >> x >> y;
            if(y == "favourably")
                ending.insert(x);
            else if(y != "catastrophically"){
                adjs[x].push_back(stoi(y));
                int z, zz;
                cin >> z >> zz;
                adjs[x].push_back(z), adjs[x].push_back(zz);
            }           
        }
        for(int i = 0; i <= 400; i++)
            dp[i] = -1;
        cout << cdp(1) << endl;
    }
}