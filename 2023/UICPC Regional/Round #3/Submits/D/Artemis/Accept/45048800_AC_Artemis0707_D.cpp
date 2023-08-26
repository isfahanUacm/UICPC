#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sm(const string& a, ll index) {
    if (index >= a.length()) {
        return 0;
    }
    ll x = 0;
    for (ll i = index; i < a.length(); ++i) {
        x += a[i] - '0';
    }
    return x;
}

long long tenp(ll ind) {
    ll f = 1;
    for (ll i = 0; i < ind; ++i) {
        f *= 10;
    }
    return f;
}

long long solve(long long x) {
    if (x < 0) {
        return 0;
    }
    ll ind = 0;
    long long ans = 0;
    while (x != 0) {
        string a = to_string(x);
        reverse(a.begin(), a.end());
        if (a[ind] != '0') {
            long long prev = sm(a, ind + 1);
            ans += prev * (tenp(ind)) +
                    (a[ind] - '0') +
                    ((a[ind] - '0' - 1) * (tenp(ind) - 1)) +
                    45 * tenp(ind - 1) * (ind);

            a[ind]--;
            reverse(a.begin(), a.end());
            x = stoll(a);
        }
        else {
            ind++;
        }
    }

    return ans;
}

int main() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        long long a, b;
        cin >> a >> b;
        cout << solve(b) - solve(a - 1) << endl;
    }
}
