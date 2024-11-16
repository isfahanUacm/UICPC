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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> sub(n + 1);
    sub[0] = 0;
    for (int i = 0; i < n; i++)
    {
        sub[i + 1] = arr[i] - sub[i];
    }
    int min_e = *min_element(all(sub));
    int first_range = -min_e;
    sub[0] = 1000000000;
    for (int i = 0; i < n; i++)
    {
        sub[i + 1] = arr[i] - sub[i];
    }
    int last_range = 1000000000 + *min_element(all(sub));
    cout << max(last_range - first_range + 1, 0);

    return 0;
}