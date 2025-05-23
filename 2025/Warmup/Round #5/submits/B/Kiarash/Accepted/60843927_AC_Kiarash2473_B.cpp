#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll arr[26];
    for (int i = 0; i < 26; i++)
        cin >> arr[i];
    ll ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ans += (i + 1) * (arr[s[i] - 97]);
    }
    sort(arr, arr + 26);
    for (int i = s.size() + 1; i <= s.size() + k; i++)
    {
        ans += arr[25] * i;
    }
    cout << ans << endl;

    return 0;
}