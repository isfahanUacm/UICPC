#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define watch(x) cout << #x << " : " << x << endl
const ll maxN = 2001;

int main()
{
    ll l, n;
    while(cin >> l >> n)
    {
        vector<pair<ll, char>> ants(n);
        ll t = LLONG_MIN;
        for(ll i = 0; i < n; i++)
        {
            cin >> ants[i].first >> ants[i].second;
        }
        sort(ants.begin(), ants.end());
        vector<ll> ansList;
        for(ll i = 0; i < n; i++)
        {
            ll value;
            if(ants[i].second == 'R')
            {
                value = abs(l - ants[i].first);
            }
            else
            {
                value = ants[i].first;
            }
            if(t < value)
            {
                ansList.clear();
                ansList.push_back(i);
            }
            else if(t == value)
            {
                ansList.push_back(i);
            }
            t = max(t, value);
        }
        cout << "The last ant will fall down in " << t << " seconds - started at ";
        multiset<ll> ans;
        for(ll i: ansList)
        {
            ll count = 0;
            if(ants[i].second == 'L')
            {
                for(ll j = i - 1; j >= 0; j--)
                {
                    if(ants[j].second != ants[i].second)
                    {
                        count++;
                    }
                }
                ans.insert(ants[i - count].first);
            }
            else
            {
                for(ll j = i + 1; j < n; j++)
                {
                    if(ants[j].second != ants[i].second)
                    {
                        count++;
                    }
                }
                ans.insert(ants[i + count].first);
            }
        }
        auto it = ans.begin();
        cout << *it;
        it++;
        while(it != ans.end())
        {
            cout << " and " << *it;
            it++;
        }
        cout << "." << endl;
    }
    return 0;
}
