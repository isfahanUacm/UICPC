#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ll tc;
    cin >> tc;
    while (tc--) {
        ll n;
        cin >> n;
        ll arr[n];

        for (ll i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        ll ans = 0;
        int cnt[2000];
        memset(cnt, 0, sizeof(cnt));

        for (ll i = 0; i < n; ++i) {
            vector<ll> temp;
            ll sm = 0;
            for (int j = 0; j <= 1010; ++j) {
                if (cnt[j] != 0) {
                    if (j < arr[i])
                        temp.push_back(cnt[j]);
                    else if (j > arr[i])
                        sm++;
                }
            }

            if (temp.empty()) {
                if (sm != 0)
                    ans++;
                cnt[arr[i]]++;
                continue;
            }

            if (sm == 0) {
                cnt[arr[i]]++;
                continue;
            }

            ll step = 1;

            for (auto x : temp)
                step *= (x + 1);

            ans += step;

            cnt[arr[i]]++;
        }

        cout << ans << endl;
    }
}