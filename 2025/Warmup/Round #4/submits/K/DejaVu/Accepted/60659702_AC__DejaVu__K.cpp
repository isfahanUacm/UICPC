#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;
    vector<int> arr(n, 0);
    for (int i = 0; i < d; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        arr[l]++;
        arr[r]++;
    }
    sort(all(arr));
    int max_arr = arr[n - 1];
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        ms.insert(max_arr - arr[i]);
    }
    auto o = ms.end();
    o--;
    while (*ms.begin() != *o)
    {
        auto se = ms.end();
        se--;
        int second = *se;
        second--;
        ms.erase(se);
        auto fe = ms.end();
        fe--;
        int first = *fe;
        first--;
        ms.erase(fe);
        ms.insert(first);
        ms.insert(second);

        o = ms.end();
        o--;
    }
    cout << max_arr - *(ms.begin());

    return 0;
}