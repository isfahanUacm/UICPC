#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n)
#define sint(s) string (s); cin >> (s)
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n'
#define int ll
// #define endl '\n'

void solve()
{
    int n, m, k; cin >> n >> m >> k;
    vector<pInt> v(n);
    for(auto& x : v) cin >> x.first >> x.second;

    vector<int> rev(k); vin(rev);

    bool left = false;
    set<int> mark;
    set<int> id;
    map<int, pInt> mp;
    set<int> broken;
    set<int> unbroken;
    int l=0, r=0;
    int j = 0;
    for(int i=0; i<n; i++)
    {
        auto cur = v[i];
        if(id.find(cur.first) != id.end() && mark.find(cur.first) == mark.end())
        {
            if(broken.find(mp[cur.first].second) != broken.end())
            {
                broken.erase(mp[cur.first].second);
            }

            mp[cur.first] = {cur.second , (left ? --l : ++r)};
            id.insert(cur.first);
            if(cur.second == 0) broken.insert(mp[cur.first].second);
            else unbroken.insert(mp[cur.first].second);
        }
        else if(id.size() < m)
        {
            // cout << id.size() << " < " << m << endl;
            mp[cur.first] = {cur.second , (left ? --l : ++r)};
            id.insert(cur.first);
            if(cur.second == 0) broken.insert(mp[cur.first].second);
            else unbroken.insert(mp[cur.first].second);
        }
        else if(!broken.empty())
        {
            if(!left) {mark.insert(*broken.begin()); broken.erase(broken.begin());}
            else {mark.insert(*(--broken.end())); broken.erase(--broken.end());}
            
            mp[cur.first] = {cur.second , (left ? --l : ++r)};
            id.insert(cur.first);
            if(cur.second == 0) broken.insert(mp[cur.first].second);
            else unbroken.insert(mp[cur.first].second);
        }
        else if(cur.second == 1)
        {
            // cout << "HERE" << endl;
            if(!left) {mark.insert(*unbroken.begin()); unbroken.erase(unbroken.begin());}
            else {mark.insert(*(--unbroken.end())); unbroken.erase(--unbroken.end());}

            mp[cur.first] = {cur.second , (left ? --l : ++r)};
            id.insert(cur.first);
            if(cur.second == 0) broken.insert(mp[cur.first].second);
            else unbroken.insert(mp[cur.first].second);

            // cout << "END" << endl;
        }

        if(j<rev.size() && i+1 == rev[j]){
            left = !left;
            j++;
        }

        // for(auto x : mp) cout << x.first << ',' << x.second.first << ',' << x.second.second << ' '; cout << endl;        
    }

    vector<pInt> ans;
    for(auto x : mp)
    {
        if(mark.find(x.second.second) == mark.end())
        {
            ans.push_back({x.second.second, x.first});
            // for(auto x : mp) cout << x.first << ',' << x.second.first << ',' << x.second.second << ' '; cout << endl;
        }
    }

    sort(ans.begin(), ans.end());
    if(left) reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for(auto x : ans) cout << x.second << ' '; cout << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}