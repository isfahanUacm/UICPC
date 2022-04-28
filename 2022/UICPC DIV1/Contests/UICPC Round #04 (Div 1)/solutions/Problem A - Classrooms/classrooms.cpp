#include <bits/stdc++.h>
using namespace std;

// Classrooms

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2){
    return p1.second < p2.second;
}

int n, k;
pair<int, int> intervals[200003];
multiset<int> classes;

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> intervals[i].first >> intervals[i].second;
    sort(intervals, intervals+n, cmp);
    for(int i = 0; i < k; i++)
        classes.insert(0);
    int ans = 0;
    for(int i = 0; i < n; i++){
        auto it = classes.lower_bound(intervals[i].first);
        if(it == classes.begin())
            continue;
        it = prev(it);
        classes.erase(it);
        classes.insert(intervals[i].second);
        ans++;
    }
    cout << ans << endl;
}