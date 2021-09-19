#include <bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int, int>>> ans;
pair<int, pair<int, int>> colortape[100003];
pair<int, vector<int>> indexx[100003]; 
set<int> st;
int a;
int n;

bool cmp (pair<int, vector<int>> v1, pair<int, vector<int>> v2){
    if(v1.second.empty())
        return false;
    if(v2.second.empty())
        return true;
    return v1.second.back() - v1.second[0] >  v2.second.back() - v2.second[0];
}



int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        indexx[a-1].second.push_back(i);
        indexx[a-1].first = a;
    }
    sort(indexx, indexx+n, cmp);
    for (int i = 0; i < n; ++i) {
        if(indexx[i].second.empty())
            break;
        auto it1 = st.upper_bound(indexx[i].second.back());
        auto it2 = st.upper_bound(indexx[i].second[0]);
        if(it1 != it2){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        ans.push_back({indexx[i].first, {indexx[i].second[0], indexx[i].second.back()}});
        for (int idx : indexx[i].second) {
            st.insert(idx);
        }
    }
    cout << ans.size() << endl;
    for (auto vv: ans) {
        cout << vv.second.first + 1 << " " << vv.second.second + 1 << " " <<  vv.first << endl;
    }
    return 0;
}

