#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("cubes.in", "r", stdin);

    int t;
    cin >> t;
    int m = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        sort(all(nums));
        vector<ll> ans(n);
        int ans_ind = 0;
        int tmp = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (tmp % 2 == 0)
            {
                ans[n - ans_ind - 1] = nums[i];
                tmp++;
            }
            else
            {
                ans[ans_ind] = nums[i];
                ans_ind++;
                tmp++;
            }
        }

        cout << "Case " << m << ":" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        m++;
    }

    return 0;
}