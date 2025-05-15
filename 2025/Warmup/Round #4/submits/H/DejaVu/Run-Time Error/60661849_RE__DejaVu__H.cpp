#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    ll s, f;
    cin >> n >> s >> f;
    vector<pair<ll, ll>> be(n);
    for (int i = 0; i < n; i++)
    {
        cin >> be[i].first >> be[i].second;
    }
    map<ll, ll> breaks;
    vector<ll> br;
    for (int i = 0; i < n; i++)
    {
        if (be[i].first > s)
        {
            ll score = breaks[be[i].first];
            breaks[be[i].first] = score + 1;
            br.push_back(be[i].first);
        }
        if (be[i].second < f)
        {
            ll score = breaks[be[i].second];
            breaks[be[i].second] = score - 1;
            br.push_back(be[i].second);
        }
    }
    sort(all(br));
    auto last = unique(all(br));
    br.erase(last, br.end());
    vector<ll> a(br.size() + 1);

    for (int i = 0; i < n; i++)
    {
        if (be[i].first < s && be[i].second > s)
            a[0]++;
    }
    
    for (int i = 0; i < br.size(); i++)
    {
        ll socre = breaks[br[i]];
        a[i + 1] = socre + a[i];
    }

    vector<ll> weight;
    weight.push_back(br[0] - s);
    for (int i = 1; i < br.size(); i++)
    {
        weight.push_back(br[i] - br[i - 1]);
    }
    weight.push_back(f - br[br.size() - 1]);

    vector<ll> cnt(1e6, 0);
    for (int i = 0; i < a.size(); i++)
    {
        cnt[a[i]] += weight[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += cnt[i];
        cout << sum << " ";
    }

    return 0;
}