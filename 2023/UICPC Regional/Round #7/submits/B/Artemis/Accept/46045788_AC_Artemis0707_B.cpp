#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    string ans;

    unordered_map<char,char> mp;
    mp['R'] = 'S';
    mp['B'] = 'K';
    mp['L'] = 'H';
    string mov[] = {"RBL", "RLB", "LRB", "LBR", "BLR","BRL"};
    ll i=0;
    while (i < s.length()){
        bool f = true;
        if( i < s.length() - 2){
            for (auto t:mov){
                if (s.substr(i,3) == t){
                    ans += "C";
                    i += 3;
                    f = false;
                    break;
                }
            }
        }
        if(f){
            ans += mp[s[i]];
            i++;
        }
        
    }
    cout<<ans<<endl;
}