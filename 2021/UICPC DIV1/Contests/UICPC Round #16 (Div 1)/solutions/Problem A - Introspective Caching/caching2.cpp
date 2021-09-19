#include <bits/stdc++.h>
using namespace std;

// Introspective Caching

// In caches, when a data is missed the omptimal and greedy strategy is to replace data with farest upcoming access.

int c, n, a, q[100003], i, ans = 0, j;
set<int> cache, indices[100003];
priority_queue<pair<int, int>> pq;


int main(){
    cin >> c >> n >> a;
    for(i = 0; i < a; i++)
        cin >> q[i];
    for(i = 0; i < a; i++){
        if(cache.find(q[i]) == cache.end())
            cache.insert(q[i]), ans++;
        if(cache.size() == c)
            break;
    }
    if(i == a){
        cout << ans << endl;
        return 0;
    }
    for(j = 0; j < n; j++)
        indices[j].insert(INT_MAX);
    for(j = i; j < a; j++)
        indices[q[j]].insert(j);
    for(int s : cache)
        pq.push({*indices[s].upper_bound(i-1), s});
    for(; i < a; i++){
        if(cache.find(q[i]) == cache.end()){
            pair<int, int> u = pq.top();
            pq.pop();
            cache.erase(u.second), cache.insert(q[i]), ans++;
        }
        pq.push({*indices[q[i]].upper_bound(i), q[i]});
    }
    cout << ans << endl;
}