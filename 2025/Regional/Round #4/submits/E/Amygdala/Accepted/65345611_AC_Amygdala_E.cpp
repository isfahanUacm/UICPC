#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';
#define pb push_back

const int N = 2e5+9;

void solve()
{
    int yellow=0, red=0;
    for(int COUNTER=0; COUNTER<10; COUNTER++)
    {
        int n;

        cin >> n;
        vector<pInt> y(n);
        loop(n, i) cin >> y[i].first >> y[i].second;

        cin >> n;
        vector<pInt> r(n);
        loop(n, i) cin >> r[i].first >> r[i].second;

        vector<pair<double, char>> all;
        for(auto x : y)
        {
            double dist=0;
            dist += (x.first-144) * (x.first-144);
            dist += (x.second-84) * (x.second-84);
            dist = sqrt(dist);
            all.emplace_back(dist, 'y');
        }
        for(auto x : r)
        {
            double dist=0;
            dist += (x.first-144) * (x.first-144);
            dist += (x.second-84) * (x.second-84);
            dist = sqrt(dist);
            all.emplace_back(dist, 'r');
        }

        std::sort(all.begin(), all.end());

        int index = 0;
        while(index<all.size() && all[index].second == all[0].second)
        {
            if(all[0].second == 'y') yellow++;
            else red++;

            index++;
        }
    }

    cout << yellow << ' ' << red;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}