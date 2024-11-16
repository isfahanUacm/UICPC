#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> r(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> r[i];

    int ans = 0;
    if (h[0] > r[0])
    {
        cout << ans;
        return 0;
    }
    else if (h[0] == r[0])
    {
        for (int i = 1; i < n; i++)
        {
            if (h[i] > r[i])
            {
                cout << ans;
                return 0;
            }
            else if (h[i] < r[i])
            {
                cout << ans + 1;
                return 0;
            }
            else
                continue;
        }
        cout << ans;
    }
    else
    {
        int add = r[0] - h[0];
        for (int i = 0; i < n; i++)
            h[i] += add;
        ans += add;
        for (int i = 1; i < n; i++)
        {
            if (h[i] > r[i])
            {
                cout << ans;
                return 0;
            }
            else if (h[i] < r[i])
            {
                cout << ans + 1;
                return 0;
            }
            else
                continue;
        }
        cout << ans;
    }

    return 0;
}