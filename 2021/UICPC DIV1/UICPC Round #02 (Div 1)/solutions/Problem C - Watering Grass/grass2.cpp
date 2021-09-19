#include <bits/stdc++.h>
using namespace std;

// Watering Grass

int n;
double l, w;

vector<pair<double, double>> intervals;

int solve(){
    if(intervals.empty())
        return -1;
    if(intervals[0].first > 0.0)
        return -1;
    int ans = 1;
    double coverage = intervals[0].second;
    if(coverage >= l)
        return ans;
    int ptr = 0;
    while(ptr < n){
        double max_right = -1;
        int cand;
        for(int j = ptr + 1; j < n; j++)
            if(intervals[j].first <= coverage && intervals[j].second > coverage && intervals[j].second >= max_right){
                max_right = intervals[j].second;
                cand = j;
            }
        if(max_right == -1)
            return -1;
        ans++;
        coverage = intervals[cand].second;
        if(coverage >= l)
            return ans;
        ptr = cand;
    }
    return -1;
}

int main(){
    double x, r, d, a, b;
    while(cin >> n >> l >> w){
        intervals.clear();
        for(int i = 0; i < n; i++){
            cin >> x >> r;
            if(r < w/2)
                continue;
            d = sqrt(r * r - (w * w)/4);
            a = x - d, b = x + d;
            if(b < 0.0 || a > l)
                continue;
            intervals.push_back({max(0.0, a), min(l, b)});
        }
        n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const pair<double, double>& p1, const pair<double, double>& p2){
            if(p1.first == p2.first)
                return p1.second - p1.first > p2.second - p2.first;
            return p1.first < p2.first;
        }); 
        cout << solve() << endl;
    }
}