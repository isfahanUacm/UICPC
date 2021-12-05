#include <bits/stdc++.h>
using namespace std;

// Memory Match

int cnt = 1;
map<string, int> id;
inline int gid(string name){
    if(id.find(name) != id.end())
        return id[name];
    return id[name] = cnt++;
}

int n, cards[1003];
set<int> deck;

int main(){
    int k, x, y;
    string p, q;
    cin >> n >> k;
    int ans = 0;
    while(k--){
        cin >> x >> y >> p >> q, cards[x-1] = gid(p), cards[y-1] = gid(q);
        if(p == q)
            ans--;
    }
    int unk = 0;
    for(int i = 0; i < n; i++){
        if(!cards[i])
            unk++;
        else if(deck.find(cards[i]) == deck.end())
            deck.insert(cards[i]);
        else
            ans++, deck.erase(cards[i]);
    }
    if(unk == deck.size())
        ans += unk;
    else if(unk == 2)
        ans++;
    cout << ans << endl;
}