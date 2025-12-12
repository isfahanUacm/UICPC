#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#define F first
#define S second
#define pb push_back
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define int long long
using namespace std;
const int MOD = 1e4;
void constructLps(vector<int> &pat, vector<int> &lps)
{
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < pat.size())
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }

        else
        {
            if (len != 0)
            {

                // Update len to the previous lps value
                // to avoid reduntant comparisons
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> search(vector<int> &pat, vector<int> &txt)
{
    int n = txt.size();
    int m = pat.size();

    vector<int> lps(m);
    vector<int> res;

    constructLps(pat, lps);
    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
            if (j == m)
            {
                res.push_back(i - j);
                j = lps[j - 1];
            }
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return res;
}

int32_t main()
{
    fast
        vector<int>
            txt, pat;
    int n, m, last;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        // cin >> x;
        if (i == 0)
        {
            last = x;
            continue;
        }
        txt.push_back((x - last + MOD) % MOD);
        last = x;
    }
    for (int i = 0; i < m; i++)
    {
        int x = b[i];
        // cin >> x;
        if (i == 0)
        {
            last = x;
            continue;
        }
        pat.push_back((x - last + MOD) % MOD);
        last = x;
    }
    vector<int> res = search(pat, txt);
    int x = MOD;
    if (res.size() == 0)
    {
        cout << 0 << ' ' << 0 << endl;
        return 0;
    }
    else
    {
        vector<int> num;
        for (int i = 0; i < res.size(); i++)
        {
            num.push_back((b[0] - a[res[i]] + MOD) % MOD);
        }
        sort(num.begin(), num.end());
        vector<pair<int, int>> ans;
        ans.pb({1, num[0]});
        for (int i = 1; i < num.size(); i++)
        {
            if (num[i] == ans[ans.size() - 1].S)
                ans[ans.size() - 1].first++;
            else
                ans.pb({1, num[i]});
        }
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        int i = 0;
        while ((i < ans.size()) && (ans[i + 1].F == ans[i].F))
            i++;
        cout << ans[i].S << ' ' << ans[i].F << endl;
    }
    return 0;
}