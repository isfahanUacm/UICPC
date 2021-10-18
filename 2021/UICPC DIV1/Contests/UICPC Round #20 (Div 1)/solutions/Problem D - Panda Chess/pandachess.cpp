#include <bits/stdc++.h>
using namespace std;

// Panda Chess

#define num long long int

int n, m, d;
int indg[100003];
map<num, int> mp;
map<int, int> mp2;
set<int> outdg[100003];
vector<int> order;
vector<int> lis;

void kahn(){
    int x;
    for(int i = 0; i < n; i++)
        if(indg[i] == 0){
            x = i;
            break;
        }
    order.push_back(x);
    bool end = false;
    while(!end){
        end = true;
        for(int i : outdg[x]){
            indg[i]--;
            if(indg[i] == 0){
                x = i;
                order.push_back(x);
                end = false;
            }
        }
    }
}

int main(){
    cin >> n >> m >> d;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        num x, y;
        cin >> x >> y;
        if(mp.find(x) == mp.end())
            mp[x] = cnt++;
        if(mp.find(y) == mp.end())
            mp[y] = cnt++;
        if(outdg[mp[x]].find(mp[y]) == outdg[mp[x]].end()){
            outdg[mp[x]].insert(mp[y]);
            indg[mp[y]]++;
        }
    }
    int ans = 0;
    kahn();
    vector<int> v;
    for(int i = 0; i < n; i++){
        num x;
        cin >> x;
        if(mp.find(x) == mp.end())
            ans++;
        else
            v.push_back(mp[x]);
    }
    for(int i = 0; i < order.size(); i++)
        mp2[order[i]] = i;
    for(int i = 0; i < v.size(); i++){
        if(mp2.find(v[i]) != mp2.end()){
            auto it = lower_bound(lis.begin(), lis.end(), mp2[v[i]]);
            if(it == lis.end())
                lis.push_back(mp2[v[i]]);
            else
                *it = mp2[v[i]];
        }    
    }
    ans += v.size() - lis.size() + n - lis.size();
    cout <<  ans << endl;
}