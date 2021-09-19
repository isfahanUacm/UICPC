#include <bits/stdc++.h>
using namespace std;

// Entertainment Box

int n, k;
pair<int, int> shows[100003];
multiset<int> tapes;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2){
    return p1.second < p2.second;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> shows[i].first >> shows[i].second;
    sort(shows, shows+n, cmp);
    for(int i = 0; i < k; i++)
        tapes.insert(0);
    int ans = 0;
    for(int i = 0; i < n; i++){
        auto it = tapes.lower_bound(shows[i].first);
        if(it != tapes.end() && *it == shows[i].first){
            ans++;
            tapes.erase(it);
            tapes.insert(shows[i].second);
        }
        else if(it != tapes.begin()){
            ans++;
            tapes.erase(prev(it));
            tapes.insert(shows[i].second);
        }
    }
    cout << ans << endl;
}