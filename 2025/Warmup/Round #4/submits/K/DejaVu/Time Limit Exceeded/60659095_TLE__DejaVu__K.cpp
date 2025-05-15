#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;
    vector<int> arr(n, 0);
    for (int i = 0; i < d; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        arr[l]++;
        arr[r]++;
    }
    sort(all(arr));
    int max_arr = arr[n - 1];
    for (int i = 0; i < n; i++)
    {
        arr[i] = max_arr - arr[i];
    }
    while (arr[0] != arr[n - 1])
    {
        arr[0]--;
        arr[1]--;
        sort(all(arr));
        reverse(all(arr));
    }
    cout << max_arr - arr[0];

    return 0;
}