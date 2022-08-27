#include <bits/stdc++.h>
using namespace std;

bool pair_comparator(pair<int, int> a, pair<int, int> b)
{
    // if (a.second != b.second)
    //     return a.second < b.second;
    // else
    //     return a.first < b.first;
    if (a.first + a.second != b.first + b.second)
        return a.first + a.second < b.first + b.second;
    else
        return a.first < b.first;
}

int main()
{
    int n, ti, hi;
    cin >> n;
    vector<pair<int, int>> stores(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ti >> hi;
        stores[i] = make_pair(ti, hi);
    }
    sort(stores.begin(), stores.end(), pair_comparator);

    int cur_time = 0;
    int visited_count = 0;

    // cout << "---------";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "ti: " << stores[i].first << " hi:" << stores[i].second << "\n";
    // }
    // cout << "---------";

    for (int i = 0; i < n; i++)
    {
        // cout << "ti: " << stores[i].first << " hi:" << stores[i].second << "\n";
        if (stores[i].first + cur_time <= stores[i].second)
        {
            // cout << "visited\n";
            visited_count++;
            cur_time += stores[i].first;
        }
    }

    // cout << "visited_count: ";
    cout << visited_count;

    return 0;
}