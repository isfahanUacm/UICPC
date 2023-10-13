#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(pair<string, ll> a, pair<string, ll> b){
    if(a.second < b.second){
        return true;
    }
    else if (a.second == b.second){
        if(a.first < b.first){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

map<char, pair<ll,ll>> keyboard;

int main(){
    keyboard['q'] = {0,0};
    keyboard['w'] = {0,1};
    keyboard['e'] = {0,2};
    keyboard['r'] = {0,3};
    keyboard['t'] = {0,4};
    keyboard['y'] = {0,5};
    keyboard['u'] = {0,6};
    keyboard['i'] = {0,7};
    keyboard['o'] = {0,8};
    keyboard['p'] = {0,9};
    keyboard['a'] = {1,0};
    keyboard['s'] = {1,1};
    keyboard['d'] = {1,2};
    keyboard['f'] = {1,3};
    keyboard['g'] = {1,4};
    keyboard['h'] = {1,5};
    keyboard['j'] = {1,6};
    keyboard['k'] = {1,7};
    keyboard['l'] = {1,8};
    keyboard['z'] = {2,0};
    keyboard['x'] = {2,1};
    keyboard['c'] = {2,2};
    keyboard['v'] = {2,3};
    keyboard['b'] = {2,4};
    keyboard['n'] = {2,5};
    keyboard['m'] = {2,6};
    
    ll t;
    cin >> t;
    while(t--){
        string s;
        ll n;
        cin >> s >> n;
        vector<pair<string, ll>> v(n);
        for(ll i = 0; i < n; i++){
            cin >> v[i].first;
            v[i].second = 0;
            for(ll j = 0; j < v[i].first.size(); j++){
                v[i].second += abs(keyboard[v[i].first[j]].first - keyboard[s[j]].first) + abs(keyboard[v[i].first[j]].second - keyboard[s[j]].second);
            }
        }
        sort(v.begin(), v.end(), cmp);
        for(ll i = 0; i < n; i++){
            cout << v[i].first << " " << v[i].second << endl;
        }
        
    }


    return 0;
}