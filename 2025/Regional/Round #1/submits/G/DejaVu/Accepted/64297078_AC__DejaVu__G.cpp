#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("jenga.in", "r", stdin);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        if (n % 3 == 0)
        {
            cout << "Case " << i << ": Wahdan\n";
        }
        else
        {
            cout << "Case " << i << ": Bakkar\n";
        }
    }

    return 0;
}