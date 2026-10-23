#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;
using pll = pair<long long, long long>;
using ull = unsigned long long;
#define ff first
#define all(x) (x).begin(), (x).end()
#define ss second
#define MP make_pair
#define pb push_back
#define pf push_front
#define set_dec(x) cout << fixed << setprecision(x);
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int> a(n), dif1(n, 0), dif2(n, 0);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        sort(all(a));
        unique(all(a));
        int k = a.back() - a.front() - a.size() + 1;
        n = a.size();
        vector<int> cost1(n, 0), cost2(n, 0);
        int ans = n - 1;
        for (int i = 0; i < n; i++)
        {
            cost1[i] = mp[a[i]];
            if (i)
            {
                cost1[i] += cost1[i - 1];
                dif1[i] = dif1[i - 1] + a[i] - a[i - 1] - 1;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            cost2[i] = mp[a[i]];
            if (i != n - 1)
            {
                cost2[i] += cost2[i + 1];
                dif2[i] = dif2[i + 1] + a[i + 1] - a[i] - 1;
            }
        }
        reverse(all(dif2));
        reverse(all(cost2));
        for (int i = 0; i < n; i++)
        {
            int anst = 0;
            int cs = 0;
            if (i)
            {
                anst = cost1[i - 1];
                cs = dif1[i - 1];
            }
            auto p = lower_bound(all(dif2), k - cs);
            if (p != dif2.end())
            {
                int idx = p - dif2.begin();
                ans = min(ans, anst + cost2[idx]);
               // cout << i << " : " << i << " " << cs << " -> " << idx << " " << cost2[idx] << endl;
            }
        }
        if (k < 0) {
            cout << 0 << endl;
            continue;
        }
        cout << ans << endl;
    }
}
