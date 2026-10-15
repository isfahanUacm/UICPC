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
        vector<int> a(n);
        vector<pii> w(n);
        set<int> st;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            st.insert(a[i]);
            mp[a[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> w[i].ff;
            w[i].ss = i + 1;
        }
        sort(all(w));
        reverse(all(w));
        ll s = 0;
        for (int i = 0; i < n; i++)
        {
            if (w[i].ss < *st.begin())
                continue;
            auto p = st.lower_bound(w[i].ss);
            while (*p > w[i].ss)
                p--;
            // cout << w[i].ss << " : " << *p << " " << endl;
            mp[*p]--;
            s += w[i].ff;
            if (!mp[*p])
                st.erase(*p);
        }
        cout << s << endl;
    }
}