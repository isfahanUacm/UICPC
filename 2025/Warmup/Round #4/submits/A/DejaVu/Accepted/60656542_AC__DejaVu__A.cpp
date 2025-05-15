#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int ans_1 = 0;
        int ans_0 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                ans_1++;
            else
                ans_0++;
        }
        ans_1 *= n - 1;
        ans_1 += ans_0;
        cout << ans_1 << endl;
    }

    return 0;
}