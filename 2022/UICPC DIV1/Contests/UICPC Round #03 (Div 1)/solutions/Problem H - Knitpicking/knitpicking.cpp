// Knitpicking

#include <bits/stdc++.h>
using namespace std;

struct torobche{
    int left = 0, right = 0, any = 0;
};

map<string, torobche> mp;

int main(){
    int n;
    cin >> n;
    while(n--){
        string w, d;
        int k;
        cin >> w >> d >> k;
        if(d == "any")
            mp[w].any = k;
        else if(d == "left")
            mp[w].left = k;
        else if(d == "right")
            mp[w].right = k;   
    }
    int kolish = 0, ans = 0;
    for(auto it : mp){
        kolish += it.second.any;
        kolish += it.second.left;
        kolish += it.second.right;
        ans += max(1, max(it.second.left, it.second.right));
    }
    if(ans == kolish){
        cout << "impossible" << endl;
    }
    else{
        cout << ans + 1 << endl;
    }
}