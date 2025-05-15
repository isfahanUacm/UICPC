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
        string n;
        cin >> n;
        int size = n.size();
        int ans = 0;
        int i;
        for (i = size - 1; i >= 0; i--)
        {
            if (n[i] == '0')
                ans++;
            else
                break;
        }
        for (int j = 0; j < i; j++)
        {
            if (n[j] != '0')
                ans++;
        }
        cout << ans << endl;
    }

    return 0;
}