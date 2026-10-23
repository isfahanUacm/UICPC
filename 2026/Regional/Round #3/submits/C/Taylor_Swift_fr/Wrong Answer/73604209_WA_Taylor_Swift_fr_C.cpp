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
        unordered_map<int, int> mp;
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            st.insert(a[i]);
            mp[a[i]]++;
        }
        sort(all(a));

        vector<int> b = a;
        int l = 0, r = n - 1;
        for (int i = 0; i < n && r - l; i++)
        {
            if (a[r] - a[l] < st.size())
                break;
            if (a.back() - *(a.rbegin() - 1) < a[l + 1] - a[l])
            {
                mp[a[l]]--;
                if (!mp[l])
                    st.erase(a[l]);
                l += 1;
            }
            else
            {
                mp[a[r]]--;
                if (!mp[r])
                    st.erase(a[r]);
                r -= 1;
            }
        }
        cout << (int)a.size() - (r - l + 1) << endl;
    }
}