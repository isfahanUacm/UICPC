//Solution by lukasP (Lukáš Poláček)
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> shows;


int main()
{
    int n, k, res = 0;
    cin>>n>>k;
    shows.resize(n);
    for(int i=0; i<n; i++)
        cin>>shows[i].second>>shows[i].first;
    sort(shows.begin(), shows.end());
    multiset<int, greater<int>> ended;
    for(int i=0; i<k; i++) 
        ended.insert(0);
    for (auto i : shows)
    {
        auto it = ended.lower_bound(i.second);
        if (it != ended.end())
        {
            ended.erase(it);
            ended.insert(i.first);
            res++;
        }
    }
    cout << res << endl;
}
